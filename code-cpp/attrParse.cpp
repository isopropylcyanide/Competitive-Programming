#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> attr;
typedef struct tag{
    string id;
    vector<attr> atb;
    vector<struct tag*> tagConnect;
}tag;


tag * initialiseTag(string id, vector<attr> & a){
    tag * newTag = new tag;
    newTag -> id = id;
    newTag -> atb = a;
    newTag -> tagConnect.resize(0);
    newTag -> tagConnect = {NULL};
    return newTag;
}

map<string, tag *>tagList;
map<string, int> scopeList;
tag * rootNode;
static int getToFirst = 0;
int N, Q;


void findAllpos(vector<int> & positions, string &str, char sub){
    size_t pos = str.find(sub, 0);
    while(pos != string::npos){
        positions.push_back(pos);
        pos = str.find(sub,pos+1);
    }
}

void parseInput2(string name, string args){
    vector<attr> myMap;
    vector<string> keys, vals;
    int i = 0;

    while ( i < args.size()){
        if (args[i] == '='){// skip two char and read until '\"'
            string newVal = "";
            i += 3;
            while (args[i] != '\"'){
                newVal += args[i];
                i++;
            }
            i += 2; // this must be ". Skip two for a new key
            vals.push_back(newVal);
        }

        else { // We are reading a key. Read until space
            string newKey;
            while(!isspace(args[i])){
                newKey += args[i];
                i++;
            }
            i += 1; // this must be space. Increment once to reach =
            keys.push_back(newKey);
        }
    }

    for (int i = 0; i < keys.size(); i++)
        myMap.push_back(make_pair(keys[i], vals[i]));

    tagList[name] = initialiseTag(name, myMap);
    scopeList[name] = 1;
    if (getToFirst == 0){
        rootNode = tagList[name];
        getToFirst ++;
    }

    // Set scope for each of the tags in the list depending on visibility
    for (auto a : scopeList)
        if (a.first != name && scopeList[name]!= 0)
            tagList[a.first] -> tagConnect.push_back(tagList[name]);
}


void queryTraverse(tag * root, vector<string> &children, int &number, string & keyAtb){
    if (root == NULL || number > children.size()){
        cout <<"Not Found!\n";
        return;
    }
    if (number == children.size()){
        // check if key is an attrib otherwise no
        bool foundState = false;

        vector<attr> :: iterator ait = root->atb.begin();
        for (; ait != root->atb.end(); ait++)
            if (ait -> first == keyAtb){
                foundState = true;
                cout << ait -> second << endl;
                return;
            }

        if (!foundState){
            cout <<"Not Found!\n";
            return;
        }
    }

    // if checkConnected is not a member, then fuck off
    string child = children[number];
    vector<tag *> :: iterator finder = find(root->tagConnect.begin(), root->tagConnect.end(),tagList[child]);
    if (finder == root->tagConnect.end()){
        cout <<"Not Found!\n";
        return;
    }

    // else we have the child, and now we have to check for their child
    else{
        tag * newChild = *finder;
        int newNumber = number + 1;
        queryTraverse(newChild, children,newNumber, keyAtb);
    }
}

void parseQueries(string & q){
    vector<string> recurTags;
    string key_Attr = "";
    vector<int> dot, tilde;

    findAllpos(dot, q, '.');
    findAllpos(tilde, q, '~');

    if (tilde.size() == 0){
        cout <<"Not Found!\n";
        return;
    }

    int start = 0;
    for (auto a : dot){
        recurTags.push_back(q.substr(start, a - start));
        start = a + 1;
    }
    // Append the tag before ~
    recurTags.push_back(q.substr(start, tilde[0] - start));
    // Add keyAttr
    key_Attr = q.substr(tilde[0] + 1);

    // Traverse the tree indicated by recurTags and check for their value given by key
    tag * rootTagNode = tagList[recurTags[0]];
    int starterChild = 1;


    if (rootTagNode == rootNode)
        queryTraverse(rootTagNode, recurTags, starterChild, key_Attr);
    else{
        cout <<"Not Found!\n";
        return;
    }

}

int main() {

    string number;
    getline(cin, number);
    stringstream numberline(number);

    numberline >> N >> Q;
    string s;

    for (int i = 0; i < N; i++){
        getline(cin, s);

        regex closingTag("</([a-z0-9]+)>");
        regex openTag("<(\\S+) (\\S+ = \".+?\")(\\S+ = \".+?\")*>");
        smatch result;

        if (regex_match(s, closingTag)){
            regex_search(s, result, closingTag);
            string nameTag = result[1];
            // set scope only if in the list
            if (scopeList.find(result[1]) != scopeList.end())
                scopeList[result[1]] = 0;
        }

        if (regex_match(s, openTag)){
            regex_search(s, result, openTag);
            parseInput2(result[1], result[2]);
        }

    }

    // Parse Queries
    for (int i = 0; i < Q; i++){
        getline(cin, s);
        parseQueries(s);
    }

    return 0;
}









//
