char toUpperCase(char ch){
 
    if(ch >= 'A' && ch <= 'Z'){
      return ch;
    }
    else{
      char temp =  ch -'a'+'A';
      return temp;
    }
}
char toLowerCase(char ch){
 
    if(ch >= 'a' && ch <= 'z'){
      return ch;
    }
    else{
      char temp =  ch -'A'+'a';
      return temp;
    }
}


int getLength(char arr[]){
  int count = 0;

 for(int i =0 ; arr[i] != '\0' ; i++){
   count ++;
 }
 return count;

}

void print(char arr[] ){
    int len=  getLength(arr);
    for(int i =0 ; i  < len ; i++){
      char temp = toUpperCase(arr[i]);
      arr[i] = temp;
      cout <<  arr[i] << endl;
      // cout <<  toLowerCase(arr[i]) << endl;
    }
  
}

void reverse(char arr[] , int size){
  int s = 0;
  int e = size-1;
  while(s <= e){
    swap(arr[s++],arr[e--]);
  }

}
int main() {
  char name[3]={'a','B','c'};
  print(name);

  return 0;
} 