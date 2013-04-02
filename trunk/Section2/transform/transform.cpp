/*
ID: hooyao1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include <algorithm>

using namespace std;


int* rotate_90(int* in, int radius){
	int* out = new int[radius*radius];
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			out[j*radius+radius-i-1]=in[i*radius+j];
		}
	}
	return out;
}

int* reflection(int* in,int radius){
	int* out = new int[radius*radius];
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			out[i*radius+radius-j-1]=in[i*radius+j];
		}
	}
	return out;
}

bool compMatrix(int* a, int* b,int radius){
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			if(a[i*radius+j]!=b[i*radius+j])
				return false;
		}
	}
	return true;
}

int findRotation(int* in,int* trg,int radius){
	int* out;
	//1
	out = rotate_90(in,radius);
	if(compMatrix(trg,out,radius)) 
		return 1;
	out = rotate_90(out,radius);
	if(compMatrix(trg,out,radius)) 
		return 2;
	out = rotate_90(out,radius);
	if(compMatrix(trg,out,radius)) 
		return 3;
	return -1;
}

int findReflection(int* in,int* trg,int radius){
	int* out = reflection(in,radius);
	if(compMatrix(out,trg,radius)){
		return 4;
	}
	return -1;
}

int main() {
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");
	int radius = 0;
	fin>>radius;

	int* src = new int[radius*radius];
	int* trg = new int[radius*radius];
	
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			char tmp;
			fin>>tmp;
			src[i*radius+j] = tmp=='@'?0:1;
		}
	}
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			char tmp;
			fin>>tmp;
			trg[i*radius+j] = tmp=='@'?0:1;
		}
	}
	int rtResult = findRotation(src,trg,radius);
	if(rtResult>0){
		fout<<rtResult<<endl;
		return 0;
	}
	int rfResult = findReflection(src,trg,radius);
	if(rfResult>0){
		fout<<rfResult<<endl;
		return 0;
	}
	int* out = reflection(src,radius);
	int cbResult = findRotation(out,trg,radius);
	if(cbResult>0){
		fout<<5<<endl;
		return 0;
	}
	if(compMatrix(trg,out,radius)){
		fout<<6<<endl;
		return 0;
	}
	fout<<7<<endl;
	return 0;
}

