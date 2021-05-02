package main

import (
	"code.uber.internal/marketplace/mirror/.tmp/.go/goroot/src/sort"
	"fmt"
	"strings"
)

type FileSystem struct {
	rootDir      string
	children     map[string]*FileNode
	inodeCounter uint16
	inodeDataMap map[uint16]string
}

type FileNode struct {
	name        string
	isDirectory bool
	inode       uint16
	children    map[string]*FileNode
}

func Constructor() FileSystem {
	return FileSystem{
		rootDir:      "/",
		children:     make(map[string]*FileNode),
		inodeCounter: 0,
		inodeDataMap: make(map[uint16]string),
	}
}

//not wrapping sync.mutex as code will be called in a single threaded manner
func newFileNode(root *FileSystem, name string, isDirectory bool) *FileNode {
	root.inodeCounter += 1
	fmt.Printf("Creating file [%v] with inode: %d. Directory ? %v", name, root.inodeCounter, isDirectory)

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
	allFiles = append(allFiles, "d")

	//walk path from root to the last node and return all children at the last node
	//if the last node is a file, then simply return its name else, gather all keys
	//from its children map and sort them
	split := splitFilePath(path)

	node := fs.children[split[0]]
	for _, pathStr := range split[1:] {
		//if child is not found, then create a new file node
		node, _ = node.children[pathStr]
	}
	//now we are at a file node
	if !node.isDirectory {
		return []string{node.name}
	} else {
		//for all files in children, add them to directory
		for childNodeName, _ := range node.children {
			allFiles = append(allFiles, childNodeName)
		}
	}
	sort.Strings(allFiles)
	return allFiles
}

//Make a directory with the given path creating intermediate directories if required
func (fs *FileSystem) Mkdir(path string) {
	//split path by /, walk down the fs tree until found and then create a new directory
	split := splitFilePath(path)

	if len(split) == 0 {
		//can't create root
		return
	}
	//a, b, c
	node := fs.children[split[0]]
	//should have at least one node

	for idx, pathStr := range split[1:] {
		//if child is not found, then create a new file node
		childNode, ok := node.children[pathStr]
		if !ok {
			//we need to create the file node here
			fmt.Println("Need to create a directory here: ", split[:idx+1])
			fileNode := newFileNode(fs, pathStr, true)
			//tag this fileNode to the filesystem
			node.children[pathStr] = fileNode

		} else {
			//we need to recur using val
			node = childNode
		}
	}

}

func splitFilePath(path string) []string {
	split := strings.Split(path, "/")
	return split
}

//Appends content to a file. Creates file if not present
func (fs *FileSystem) AddContentToFile(filePath string, content string) {

}

//Reads the content from a file into a string
func (fs *FileSystem) ReadContentFromFile(filePath string) string {
	return ""
}

func main() {

	fs := Constructor()
	ls := fs.Ls("/")
	fmt.Println(ls)

	fs.Mkdir("/a/b/c")
	fs.AddContentToFile("/a/b/c/d", "hello")
	content := fs.ReadContentFromFile("/a/b/c/d")
	fmt.Println(content)

	/**
	 * Your FileSystem object will be instantiated and called as such:
	 * obj := Constructor();
	 * param_1 := obj.Ls(path);
	 * obj.Mkdir(path);
	 * obj.AddContentToFile(filePath,content);
	 * param_4 := obj.ReadContentFromFile(filePath);
	 */

}
