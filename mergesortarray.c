#include<stdio.h>

void main(){

int i,j,k,a[50],b[50],c[50],n,m;

printf("Enter the size of the 1 array :");
scanf("%d",&n);

for(i=0;i<n;i++){
  scanf("%d",&a[i]);
}

printf("\nEnter the size of the 2 array :");
scanf("%d",&m);

for(i=0;i<m;i++){
  scanf("%d",&b[i]);
}

printf("\nThe 1 array :");

for(i=0;i<n;i++){
  printf("%d",a[i]);
}

printf("\nThe 2 array:");



for(i=0;i<m;i++){
  printf("%d",b[i]);
}

i=j=0;

for(k=0;k<(m+n);k++){

	if(i<n && j<m){
	
		if(a[i]<b[j]){
	
			c[k]=a[i];
			i++;
		}else{
		
			c[k]=b[j];
			j++;
		}
	}else {
	
		if(i<n){
			
			c[k]=a[i];
			i++;
		}
		
		if(j<m){
			
			c[k]=b[j];
			j++;
		}		
			
	}
	
	


	
}

printf("\nThe merged arrays :");


for(i=0;i<(m+n);i++){
  printf("\t%d",c[i]);
}


return;



}


