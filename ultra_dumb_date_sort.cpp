#include <iostream>

#include <bits/stdc++.h>


using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::stoi;

 

struct date{
  int day, month, year; 
};
 
/*
bool cmp(date a, date b){
  if(a.year<b.year) return true;
  if(a.year>b.year) return false;
  if(a.month<b.month) return true;
  if(a.month>b.month) return false;
  return a.day<b.day;
}
*/
/*
void dumb_sort(date arr){
    for (int i = 0; i < 4; i++ ){
        for(int j = i + 1; j < 4; j++){
            int a , aa, aaa, b, bb, bbb;
            a = arr[i].year;
            aa = arr[i].month;
            aaa = arr[i].day;
            b = arr[j].year;
            bb = arr[j].month;
            bbb = arr[j].day;
            if(a > b){
               swap(arr[i],arr[j]);
               break;
            }
            if(aa > bb){
               swap(arr[i],arr[j]);
               break;
            }
            if(aaa > bbb){
               swap(arr[i],arr[j]);
               break;
            }
        }
    }
}
*/

int main(){
  date arr[]={{28,2,2005}, {28,8,2004}, {19,1,2004}, {16,3,2002}};
  for (int i = 0; i < 4; i++ ){
        for(int j = i + 1; j < 4; j++){
            bool flag = true;
            if (arr[i].year > arr[j].year && flag){ 
                swap(arr[i], arr[j]);
                flag = false;
                
            }
            if ( arr[i].month > arr[j].month && flag){ 
                swap(arr[i], arr[j]);
                flag = false;
                
            }
            if ( arr[i].month > arr[j].month && flag){ 
                swap(arr[i], arr[j]);
                
            }
        }
    }
  for(int i=0; i<4; i++)
    cout << arr[i].day << '.' << arr[i].month << '.' << arr[i].year << endl;

  return 0;
}