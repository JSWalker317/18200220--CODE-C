#include<string>
#include<iostream>
using namespace std;
string nhapchuoi(){
	string s;
	cout<<"Nhap chuoi: ";
	cin>>s;
	return s;
}
void xuatchuoi(string s){
	cout<<"Chuoi vua nhap : ";
	cout<<s<<endl;
}
int timkiemtuyentinh(string s,char c){
	for(int i=0;i<s.length();i++){
		if(s[i]==c){
			return i;
		}
	}
	return -1;
}
int main(){
	string s=nhapchuoi();
	xuatchuoi(s);
	char c;
	cout<<"Nhap ki tu can tim:";
	cin>>c;
	cout<<"Vi tri : ";
	cout<<timkiemtuyentinh(s,c);
	return 0;
}

