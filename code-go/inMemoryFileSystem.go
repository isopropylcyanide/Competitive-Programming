package main

import (
	"fmt"
	"sort"
	"strings"
)

type inode uint16

type FileSystem struct {
	root         *FileNode
	inodeCounter inode
	inodeDataMap map[inode][]byte
}

type FileNode struct {
	name        string
	isDirectory bool
	inode       inode
	children    map[string]*FileNode
}

func New() FileSystem {
	return FileSystem{
		root: &FileNode{
			name:        "/",
			isDirectory: true,
			inode:       0,
			children:    make(map[string]*FileNode),
		},
		inodeCounter: 1,
		inodeDataMap: make(map[inode][]byte),
	}
}

func (fs *FileSystem) incrementInode() {
	fs.inodeCounter = fs.inodeCounter + 1
}

//not wrapping sync.mutex as code will be called in a single threaded manner
func newFileNode(root *FileSystem, name string, isDirectory bool) *FileNode {
	defer root.incrementInode()

	return &FileNode{
		name:        name,
		isDirectory: isDirectory,
		inode:       root.inodeCounter,
		children:    make(map[string]*FileNode),
	}
}

//Ls lists all files in the given directory with valid inputs (non recursive)
func (fs *FileSystem) Ls(path string) []string {
	var allFiles []string
	//walk path from root to the last node and return all children at the last node
	//if the last node is a file, then simply return its name else, gather all keys
	//from its children map and sort them
	node := fs.root
	for _, pathStr := range splitFilePath(path) {
		//if child is not found, then create a new file node
		node, _ = node.children[pathStr]
	}
	if !node.isDirectory {
		return []string{node.name}
	} else {
		//for all files in children, add them to directory
		for childNodeName := range node.children {
			allFiles = append(allFiles, childNodeName)
		}
	}
	sort.Strings(allFiles)
	return allFiles
}

//Make a directory with the given path creating intermediate directories if required
func (fs *FileSystem) Mkdir(path string) {
	createFileIfNotExists(path, fs, true)
}

//Appends content to a file. Creates a file if not present and appends the data present
//in the inode map
func (fs *FileSystem) AddContentToFile(filePath string, content string) {
	node := createFileIfNotExists(filePath, fs, false)
	//since input is valid, we avoid error/nil check
	appendBytes := append(fs.inodeDataMap[node.inode], []byte(content)...)
	fs.inodeDataMap[node.inode] = appendBytes
	//fs.inodeDataMap[node.inode] += byte()content
}

//Reads the content from a file into a string
func (fs *FileSystem) ReadContentFromFile(filePath string) string {
	node := createFileIfNotExists(filePath, fs, false)
	//since input is valid, we avoid error/nil check
	return string(fs.inodeDataMap[node.inode])
}

//Creates a file in memory. A directory is also a file. Returns the file node address
//of the newly created file
func createFileIfNotExists(path string, root *FileSystem, isDirectory bool) *FileNode {
	node := root.root
	for _, pathStr := range splitFilePath(path) {
		//if child is not found, then create a new file node
		if childNode, ok := node.children[pathStr]; !ok {
			//we need to create the file node here
			fileNode := newFileNode(root, pathStr, isDirectory)
			//tag this fileNode to the filesystem
			node.children[pathStr] = fileNode
			//the newly created node is used to recur
			node = fileNode
		} else {
			//recur for the already created child
			node = childNode
		}
	}
	return node
}

//f function to split a given path starting with /
//avoids the edge case where the given path is the root itself
func splitFilePath(path string) []string {
	if path == "/" {
		return []string{}
	}
	split := strings.Split(path, "/")
	return split[1:]
}

func main() {
	fs := New()
	fmt.Println(fs.Ls("/"))

	fs.Mkdir("/a/b/c")
	fs.Mkdir("/a/b/g")
	fs.Mkdir("/x/y")

	fmt.Println(fs.Ls("/"))
	fmt.Println(fs.Ls("/a"))
	fmt.Println(fs.Ls("/a/b"))
	fmt.Println(fs.Ls("/a/b/c"))

	fs.AddContentToFile("/a/b/c/d", "hello")

	fmt.Println(fs.ReadContentFromFile("/a/b/c/d"))

	fs.AddContentToFile("/a/b/c/d", " and hey")
	fmt.Println(fs.ReadContentFromFile("/a/b/c/d"))
}
