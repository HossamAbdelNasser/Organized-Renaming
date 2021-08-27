#include <iostream>
#include <dirent.h>
#include <cstdio>
#include <string>

using namespace std;

void readDir(char* pathName, string fileNames[]){
    DIR* dir = opendir(pathName);
    dirent* entity;
    entity = readdir(dir);
    int i = 0;
    while(entity != NULL) {
        fileNames[i] = entity->d_name;
         i++;
        entity = readdir(dir);
    }

    closedir(dir);
}

void filter(string fileNames[], string filterArr[]) {
    for (int i = 0; i<9; i++){
        filterArr[i] = fileNames[i+2];
    }
}

void pathname(char* pathName, string dirName[], string filterArr[]){
    
    for (int i = 0; i<9; i++) {
        dirName[i] = pathName + filterArr[i];
    }
}

void strTochar(string str[], const char* c[]) {
    for (int i = 0; i<9; i++){
    c[i] = str[i].c_str();
    }
    
}

void newNameF(string newName[], char* pathName) {
    
     for(int i=0; i<6; i++){   
     string one = to_string(i+1);
     string jpg = ".jpg";
     newName[i] = pathName + one + jpg;
     }
}

void displayList(const char* c[]){
    for (int i = 0; i<6; i++){
        cout << c[i] << endl;
    }
}

void Rename(const char* oldname[], const char* newname[]) {

        for (int i=0; i<6; i++){
            if (rename(oldname[i], newname[i])!=0) {
        cout << "Not Found\n";
    } else {
     rename(oldname[i],newname[i]);
            }
        cout<<"Success\n";
    }
}


int main(int argc, char *argv[]){

   char* pathName = "C:\\Users\\HP\\Desktop\\test\\";
   string fileNames[50];  
   string filterArr[50];
   string dirName[50];
   const char *holder[50];
   string newName[50];
   const char *newNameC[50];
   
    readDir(pathName, fileNames);
    filter(fileNames, filterArr);
    pathname(pathName,dirName,filterArr);
    strTochar(dirName, holder);
    newNameF(newName, pathName);
    displayList(holder);       
    strTochar(newName, newNameC);
    Rename(holder,newNameC);
}
