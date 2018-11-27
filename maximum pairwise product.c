#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
 long long int num[200000],big,sbig,n,i;
  long long int res=0;
  scanf("%lld",&n);    // reading the limit
  for(i=0;i<n;i++){ 
  scanf("%lld",&num[i]);  //reading the array
}
   big=0;  //finding the biggest and second biggest number
   for(i=0;i<n;i++){
   	if(num[i]>=big){
   		big=num[i];
	   }
   }  
   sbig=0;
   for(i=0;i<n;i++){
   	if((num[i]>=sbig)&&(num[i]<big)){
   		sbig=num[i];
	   }
   } 
   res=big*sbig;
   printf("%lld\n",res); //printing the result
   return 0;
}


	




