#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <stdio.h>

using namespace std;

void sortbyalph(vector<string> in) {
    sort(in.begin(), in.end(),
        [](const string& x, const string& y) {
            return x < y;
        });
};

int m(int t) {
    if (t % 60 == 0) { return 0; }
    else { return 1; }
}


int main()
{
    ifstream file("test_file.txt");
    string str="", strb="", stre="",strt="";
    string client="";
    vector<string> q;
    vector<string> in;
    int* earned;
    string* cl;
    int* clval;
    int* cldiff;
    int skip = 0;
    char c=32;
    int len = 0;
    int strnum=0;
    int n = 0, hvalue = 0, id = -1, tabl = 0;
    int ohour=0, omin=0, chour=0, cmin=0;
    if (getline(file, str)) {
        strnum++;
        for (int i = 0; (i < str.size()) && ((str[i] > 47 && str[i] < 58)); i++) {
            n = 10 * n + str[i] - 48;
            len++;
        }
        for (int i = len; (i < str.size()) && (str[i]==32); i++) {
            len++;
        }
        if(len!=str.size()){ cout << strnum; return 1; }

    }
    else { cout << strnum; return 1; }
    len = 0;
    
    earned = new int[n];
    cldiff = new int[n];
    clval = new int[n];
    cl = new string[n];
    for (int i = 0; i < n; i++) { cl[i] = ""; cldiff[i] = ohour * 60 + omin; clval[i] = 0; earned[i] = 0; }

    if (getline(file, str)) {
        strnum++;
        for (int i = 0; (i < 2) && ((str[i] > 47 && str[i] < 58)); i++) {
            ohour = 10 * ohour + str[i] - 48;
            len++;
        }
        if (len != 2) { cout << strnum; return 1; } 
        if(str[len]!=58){ cout << strnum; return 1; }
        len++;
        for (int i = len; (i < 5) && ((str[i] > 47 && str[i] < 58)); i++) {
            omin = 10 * omin + str[i] - 48;
            len++;
        }

        if (str[len] != 32) { cout << strnum; return 1; }
        len++;

        for (int i = len; (i < 8) && ((str[i] > 47 && str[i] < 58)); i++) {
            chour = 10 * chour + str[i] - 48;
            len++;
        }
        if (len != 8) { cout << strnum; return 1; }
        if (str[len] != 58) { cout << strnum; return 1; }
        len++;
        for (int i = len; (i < 11) && ((str[i] > 47 && str[i] < 58)); i++) {
            cmin = 10 * cmin + str[i] - 48;
            len++;
        }
        if (len != 11) { cout << strnum; return 1; }

        for (int i = len; (i < str.size()) && (str[i] == 32); i++) {
            len++;
        }
        if (len != str.size()) { cout << strnum; return 1; }

    }
    else { cout << strnum; return 1; }
    len = 0;

    if (chour > 23 || cmin > 59 || ohour > 23 || omin > 59) { cout << strnum; return 1; }

    for (int i = 0; i < 5; i++) { strb.append(1, str[i]); }
    for (int i = 6; i < 11; i++) { stre.append(1, str[i]); }


    if (getline(file, str)) {
        strnum++;
        for (int i = 0; (i < str.size()) && ((str[i] > 47 && str[i] < 58)); i++) {
            hvalue = 10 * hvalue + str[i] - 48;
            len++;
        }
        if (len == 0) { cout << strnum; return 1; }
        for (int i = len; (i < str.size()) && (str[i] == 32); i++) {
            len++;
        }
        if (len != str.size()) { cout << strnum; return 1; }
    }
    else { cout << strnum; return 1; }
    len = 0;

    cout << strb << endl;

    while (getline(file, str)) {
        len = 0; int br = 0;
        int hour = 0, min = 0;
        client.clear(); strt.clear();
        tabl = 0; 
        strnum++;
        id = -1;
        skip = 0;
        
        if(str.size()<9){ cout << strnum; return 1; }
        //input
        for (int i = 0; (i < 2) && ((str[i] > 47 && str[i] < 58)); i++) {
            hour = 10 * hour + str[i] - 48;
            len++;
        }
        if (len != 2) { cout << strnum; return 1; }
        if (str[len] != 58) { cout << strnum; return 1; }
        len++;
        for (int i = len; (i < 5) && ((str[i] > 47 && str[i] < 58)); i++) {
            min = 10 * min + str[i] - 48;
            len++;
        }

        if(len!=5){ cout << strnum; return 1; }

        if (hour > 23 || min > 59) { cout << strnum; return 1; }
        for (int i = 0; i < 5; i++) { strt.append(1, str[i]); }

        if (str[len] != 32) { cout << strnum; return 1; }
        len++;

        if (str[len] < 49 || str[len]>52) { cout << strnum; return 1; }
        id = str[len]-48;
        len++;

        if (str[len] != 32) { cout << strnum; return 1; }
        len++;

       
        for (int i = len; (i < str.size()) && (str[i] > 47 && str[i] < 58) || str[i] == 95 || str[i] == 45 || (str[i] > 96 && str[i] < 123); i++) {
            client.append(1, str[i]);
            len++;
        }

        if (client == "") { cout << strnum; return 1; }

        if (str[len] == 0) { br = 1; }
        if (str[len] != 32 && str[len]!= 0 ) { cout << strnum; return 1; }
        len++;

        for (int i = len; (i < str.size()) && ((str[i] > 47 && str[i] < 58)); i++) {
            tabl = 10 * tabl + str[i] - 48;
            len++;
        }if (tabl != 0) { tabl = tabl - 1; }

        if(tabl>n) { cout << strnum; return 1; }

        for (int i = len; (i < str.size()) && (str[i] == 32); i++) {
            len++;
        }
        if (br == 1) { len--; }
        if (len != str.size()) { cout << strnum; return 2; }
        //input
        cout << str << endl;
        //id=1
       
        if (id == 1) {
            if (tabl != 0) { skip = 1; }
            if (skip != 1) {
                for (int i = 0; i < n; i++) {
                    if (cl[i] == client) { cout << strt << " 13 YouShallNotPass" << endl; skip = 1; }
                }
                
            }
            if (skip != 1) {
                if (hour * 100 + min<ohour * 100 + omin || hour * 100 + min>chour * 100 + cmin) {
                    cout << strt << " 13 NotOpenYet" << endl; skip = 1;
                }
            }
            if (skip != 1) {
                in.push_back(client);
            }
        }
        //id=3
        if (id == 3) {
            if (tabl != 0) { skip = 1; }
            if (skip != 1) {
                int br = 0;
                for (int i = 0; (i < n)&&br==0; i++) {
                    if (cl[i] == "") { cout << strt << " 13 ICanWaitNoLonger!" << endl; skip = 1; br = 1; }
                }
            }
            if (skip != 1) {
                q.push_back(client);
            }
            if (skip != 1 && q.size() > n) {
                q.pop_back();
                for (auto it = in.begin(); it != in.end(); it++) {
                    if (*it == client) { in.erase(it); break; }
                }
                cout << strt << " 11 " << client << endl;
            }
        }
        //id=4
        if (id == 4) {
          
            if (tabl != 0) { skip = 1; }
            if (skip != 1) {
                for (int i = 0; i < n; i++) {
                    int br = 0;
                    if (cl[i] == client) {
                        br = 1; cl[i] = ""; 
                        clval[i] = hour * 60 + min - cldiff[i] + clval[i];
                        earned[i] = (hour * 60 + min - cldiff[i]) / 60 + m(hour*60+min-cldiff[i]) + earned[i];
                    }
                }
                if (br == 0) { cout << strt << " 13 ClientUnknown" << endl; skip = 1; }
            }
            if (skip != 1) {
                for (auto it = in.begin(); it!= in.end(); it++) {
                    if (*it == client) { in.erase(it); break; }
                }
                for (auto it = q.begin(); it != q.end(); it++) {
                    if (*it == client) { q.erase(it); break; }
                }
            }
        }
        //id=2
        if (id == 2) {
            int skip1 = 0;
            skip = 0;
            int br = 0;
            for (auto it = in.begin(); it != in.end(); it++) {
                if (*it == client) { br = 1; }
            }
            if (br == 0) { cout << strt << " 13 ClientUnknown" << endl; skip = 1; }
            br = 0;
            if (skip != 1) {
                for (int i = 0; (i < n)&&(br==0); i++) {
                    if (cl[i] == client) {
                        br = 1;
                        if (cl[tabl] != "") { cout << strt << " 13 PlaceIsBusy" << endl; skip = 1;}
                        else {
                            swap(cl[tabl], cl[i]);
                            clval[i] = hour * 60 + min - cldiff[i] + clval[i];
                            earned[i] = (hour * 60 + min - cldiff[i]) / 60 + m(hour*60+min-cldiff[i]) + earned[i];
                            cldiff[tabl] = hour * 60 + min;
                        }
                    }
                }
            }

            if (skip != 1) {
                for (auto it = q.begin(); it != q.end(); it++) {
                    if (*it == client) {
                        if (cl[tabl] == "") {
                            cl[tabl] = client; q.erase(it);
                            cldiff[tabl] = hour * 60 + min;
                            cout << strt << " 12 " << client << " " << tabl + 1 << endl;
                            skip = 1;
                            break;
                        }
                        else { cout << strt << " 13 PlaceIsBusy" << endl; skip1 = 1; }
                    }
                }
            }

            if (skip != 1 && skip1 !=1) {
                for (auto it = in.begin(); it != in.end(); it++) {
                    if (*it == client) {
                        if (cl[tabl] == "") {
                            cl[tabl] = client;
                            cldiff[tabl] = hour * 60 + min;
                            //cout << strt << " 12 " << client << " " << tabl+1 << endl;
                            break;
                        }
                        else { cout << strt << " 13 PlaceIsBusy" << endl; skip = 1; }
                    }
                }
            }
            
         }
        if (id ==4 || id==1) {
            for (int i = 0; i < n; i++) {
                if (cl[i] == "" && q.size() > 0) {
                    auto it = q.begin();
                    cl[i] = *it;
                    q.erase(it);
                    cldiff[i] = hour * 60 + min;
                    cout << strt << " 12 " << cl[i] << " " << tabl + 1 << endl;

                }
            }
        }
    }

    sortbyalph(in);
    for (auto it = in.begin(); it != in.end(); it++) {
        cout << stre << " 11 " << *it << endl;
        for (int i = 0; i < n; i++) {
            if(*it==cl[i]){ 
                clval[i] = chour * 60 + cmin - cldiff[i] + clval[i];    
                earned[i] = (chour * 60 + cmin - cldiff[i]) / 60 + m(chour*60+cmin-cldiff[i]) + earned[i];
            }
        }
    }

    cout << stre << endl;

    for (int i = 0; i < n; i++) {
        if (clval[i] / 60 > 9 && clval[i] % 60 > 9) { cout << i+1 << " " << earned[i] * hvalue << " " << clval[i] / 60 << ":" << clval[i] % 60 << endl; }
        if (clval[i] / 60 <= 9 && clval[i] % 60 > 9) { cout << i+1 << " " << earned[i] * hvalue << " 0" << clval[i] / 60 << ":" << clval[i] % 60 << endl; }
        if (clval[i] / 60 > 9 && clval[i] % 60 <= 9) { cout << i+1 << " " << earned[i] * hvalue << " " << clval[i] / 60 << ":0" << clval[i] % 60 << endl; }
        if (clval[i] / 60 <= 9 && clval[i] % 60 <= 9) { cout << i+1 << " " << earned[i] * hvalue << " 0" << clval[i] / 60 << ":0" << clval[i] % 60 << endl; }
    }
    
}



