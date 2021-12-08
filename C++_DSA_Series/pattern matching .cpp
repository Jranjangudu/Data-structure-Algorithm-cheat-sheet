/* 
   1
  121
 12321
1234321
````````````````````````
---1
--121
-12321
1234321
*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int row =1;
  while(row <= n){
    // print first space
     int space =n-row ;
     while(space){
       cout << " "; // cout << "-"
       space --;
     }

     // print second triangle
    int col =1;
    while(col <= row ){
      cout << col ;
      col++;
    }
    // print third triangle
    int start = row-1;

    while(start){
      cout << start ;
      start--;
    }
   cout << endl;
  row++;
  }
}


// -------------------------------------
/*
--> pattern
A B C D 
A B C D 
A B C D 
A B C D 

*/
//code

int main() {
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    int j = 1;
    while(j <=n ){
    char ch = 'A'+j-1;
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}

//-----------------------------------


/*
-->pattern
A 
B B 
C C C 
D D D D 

*/

int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    char ch = 'A'+i-1;
    int j =1;
    while(j <= i){
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}

// --------------------

/*
A A A A 
B B B B 
C C C C 
D D D D 

*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    char ch = 'A'+i-1;
    int j =1;
    while(j <= n){
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}
// ---------------------------
/*
A B C D 
B C D E 
C D E F 
D E F G 

*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    int j =1;
    while(j <= n){
    char ch = 'A'+i+j-2;
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}

// ------------------------------------
/*
A 
B B 
C C C 
D D D D 
*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    int j =1;
    while(j <= i){
    char ch = 'A'+i-1;
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}

// --------------------------------------------
/*
A 
B C 
C D E 
D E F G 

*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    int j =1;
    while(j <= i){
    char ch = 'A'+j+i-2;
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}

// ------------------------------------------

/*
E 
D D 
C C C 
B B B B 
A A A A A
*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    int j =1;
    while(j <= i){
    char ch = 'A'+n-i;
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}
// ------------------------------------------
/*
E 
D E 
C D E 
B C D E 
A B C D E 
*/

int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    int j =0;
    while(j < i){
    char ch = 'A'+n+j-i;
      cout << ch << " ";
      j++;
    }
   cout << endl;
   i++;
  }
}

// -----------------------------------
/*
   *
  **
 ***
****
*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
    int star = n-i;
    while(star){
      cout << " ";
      star--;
    }
    int j =1;
    while(j <= i){
      cout << "*" ;
      j++;
    }
   cout << endl;
   i++;
  }
}
// -----------------------------------
/*

* * * * 
* * * 
* * 
* 

*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
  
    int j =1;
    while(j <= n-i+1 ){
      cout << "*" <<" ";
      j++;
    }
   cout << endl;
   i++;
  }
}
// ------------------------------------.
/*
* * * * *       
 * * * * 
  * * *          
   * * 
    * 

* * * * * 
-* * * * 
--* * * 
---* * 
----* 
*/
int main() {
 
  int n;
  cout << "enter your number" << endl;
  cin >> n ;
  
  int i =1;
  while(i <= n){
     int space =i-1 ;
     while(space){
       cout << " "; // cout << "-";
       space --;
     }
    int j =1;
    while(j <= n-i+1 ){
      cout << "*" <<" ";
      j++;
    }
   cout << endl;
   i++;
  }
}