#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 128

	typedef struct stack {
		int a[MAX];
		int i;
	}stack;
	
	typedef struct queue {
		int arr[MAX];
		int i;
	}queue;

	void push(int num, stack *s) {
		s->a[s->i]= num;
		(s->i)++;
	}
	
	int pop(stack *s) {
		int t = s->a[s->i - 1];
		(s->i)--;
		return t;
	}

	int empty(stack *s) {
		return s->i == 0;
	}

	int full(stack *s) {
		return s->i == MAX;
	}
	
	void init(stack *s) {
		s->i = 0;
	}

	
	void qinit(queue *q){
		q->i = 0;
	}

	void enqueue(int d, queue *q ){
		q->arr[q->i] = d;
		(q->i)++;
	}

	int dequeue(queue *q){
		int j = 0;
		int l;
		l = q->arr[0];
		while(j < (q->i - 1)) {
			q->arr[j] = q->arr[j + 1];
			j++;
		}
		(q->i)--;
		return l;
			
	}

	int qempty(queue *q){
		return q->i == 0;
	}

	int qfull(queue *q){
		return q->i == MAX;
	}

/*functions*/

	void add(){
		stack p,q,s;
		int j = 0, k, sum, carry, i;		
		char str1[MAX], str2[MAX];
		printf("enter two numbers\n");
		scanf("%s",str1);
		scanf("%s",str2);
		
		while(str1[j] != '\0'){
			i = str1[j] - '0';
			push(i,&p);
			j++;
		}
		j = 0;
		while(str2[j] != '\0'){
			i = str2[j] - '0';
			push(i,&q); 
			j++;
		}

		while(!empty(&p) && !empty(&q)){
			i = pop(&p);
			j = pop(&q);
			sum = ( i + j + carry) % 10;
			carry = ( i + j + carry)/10;
			push(sum, &s);
		}

		if(empty(&p))
			while(!empty(&q)){
				sum = pop(&q);
				push(sum,&s);
			}
		
		if(empty(&q))
			while(!empty(&p)){
				sum = pop(&p);
				push(sum,&s);
			}
		
		while(!empty(&s)){
			printf("%d",pop(&s));
		}
		
		return;
	}		

	void subtract(){
		stack p,q,s;
		int j = 0, k, sub, carry, n1, n2, i;		
		char str1[MAX], str2[MAX];
		printf("enter two numbers\n");
		scanf("%s",str1);
		scanf("%s",str2);
		
		while(str1[j] != '\0'){
			i = str1[j] - '0';
			push(i,&p);
			j++;
		}
		j = 0;
		while(str2[j] != '\0'){
			i = str2[j] - '0';
			push(i,&q); 
			j++;
		}
			n1 = pop(&p);
			n2 = pop(&q);
		while(!empty(&p) && !empty(&q)){
			
			if(n1 < n2){
				n1 = n1 + 10;
				sub = n1 - n2;
				push(sub, &s);
			}
			else{
				sub = n1 - n2;
				push(sub, &s);
			}
			if(n1 < n2){
				n1 = pop(&p);
				n1 = n1 - 1;
				n2 = pop(&q);
			}
			else{
				n1 = pop(&p);
				n2 = pop(&q);
			}
		}

		if(empty(&p)){
			while(!empty(&q)){
			sub = pop(&q);
			push(sub, &s);
			}
			sub = pop(&s);
			sub = -1*sub;
			push(sub,&s);
			while(!empty(&s)){
				printf("%d",pop(&s));
			}
			return;
		}
		
		if(empty(&q)){
			while(!empty(&p)){
			sub = pop(&p);
			push(sub, &s);
			}
			
			while(!empty(&s)){
				printf("%d",pop(&s));
			}
			return;
		}
		
		return;
			

	}
	
		


	char * multiply(){
	    char a[MAX];
 	    char b[MAX];
	    char *p;
	    
	    printf("Enter the first number : ");
	    scanf("%s",a);
	    printf("Enter the second number : ");
	    scanf("%s",b);
	    printf("Multiplication of two numbers : ");
	    static char mul[MAX];
	    char c[MAX];
	    char temp[MAX];
	    int la,lb;
	    int i,j,k=0,x=0,y;
	    long int r=0;
	    long sum = 0;
	    la=strlen(a)-1;
	        lb=strlen(b)-1;
	   
	        for(i=0;i<=la;i++){
	                a[i] = a[i] - 48;
	        }
	
	        for(i=0;i<=lb;i++){
	                b[i] = b[i] - 48;
	        }
	
	    for(i=lb;i>=0;i--){
	         r=0;
	         for(j=la;j>=0;j--){
	             temp[k++] = (b[i]*a[j] + r)%10;
	             r = (b[i]*a[j]+r)/10;
	         }
	         temp[k++] = r;
	         x++;
	         for(y = 0;y<x;y++){
	             temp[k++] = 0;
	         }
	    }
	   
	    k=0;
	    r=0;
	    for(i=0;i<la+lb+2;i++){
	         sum =0;
	         y=0;
	         for(j=1;j<=lb+1;j++){
	             if(i <= la+j){
	                 sum = sum + temp[y+i];
	             }
	             y += j + la + 1;
	         }
	         c[k++] = (sum+r) %10;
	         r = (sum+r)/10;
	    }
	    c[k] = r;
	    j=0;
	    for(i=k-1;i>=0;i--){
	         mul[j++]=c[i] + 48;
	    }
	    mul[j]='\0';
	    return mul;
	}
	
	

	void decimaltobinary(){
	
		char str[MAX];
		int k, j=0, count, i=0, t=1, num, div;
		stack bin;
		queue q[MAX];
		scanf("%s",str);
		while(str[j] != '\0'){
			num = str[j] - '\0';
			enqueue(num, &q[0]);
			j++;
		}	
		
		while(1){
			count = 0;
			while(!qempty(&q[i])){
				k = t * dequeue(&q[i]);
				div = (k/2);
				enqueue(div, &q[i+1]);
				count++;
				if(k%2 == 1)
					t = 10;
				else
					t = 1;
			} 
			if(k % 2 == 0)
				push(0,&bin);
			else
				push(1,&bin);
			if(k == 1 && count == 1){
				while(!empty(&bin)){
					printf("%d",pop(&bin));
				}
				return;
			}
			i++;
		}

		return;
	}

	void decimaltooctal(){
	
		char str[MAX];
		int k, j=0, count, num, i=0, t=0, div;
		stack oct;
		queue q[MAX];
		scanf("%s",str);
		while(str[j] != '\0'){
			num = str[j] - '\0';
			enqueue(num, &q[0]);
			j++;
		}	
		
		while(1){
			count = 0;
			t = 0;
			while(!qempty(&q[i])){
				k = t + dequeue(&q[i]);
				div = k/8;
				enqueue(div, &q[i+1]);
				count++;
				if(k%8 != 0 && k<8)
					t = k*10;
				if(k%8 != 0 && k>8)
					t = (k - (8*div))*10;
				if(k%8 == 0)
					t = 0;
			} 
			t = k % 8;
				push(t,&oct);
			
			if(k < 8 && count == 1){
				while(!empty(&oct)){
					printf("%d",pop(&oct));
				}
				return;
			}
		}

		return;
	}
	
int main(){
	char ch, *c;
	printf("**to perform the operations enter the char infront of the operation**\n");
	printf("1] Addition \n2] Subtracton \n3] Multiplication \n4] Division \n");
	printf("5] decimal to binary  \n6] binary to deciaml \n7] decimal to octal \n8] octal to decimal \n");
	printf("9]sine 10]cosine 11]tan 12]sec 13]cosec 14]cot\n");
	while(1){
		scanf("%c",&ch);
		switch(ch){
			case '1':
				add();
			case '2':
				subtract();
			case '3':
				c =multiply();
				printf("%s",c);
				break;			
		/*	case '4':
				divide();
				break;	
		*/	case '5':
				decimaltobinary();
				break;	
			case '6':

		/*		binarytodecimal();
				break;	
		*/	case '7':
				decimaltooctal();
				break;	
		/*	case '8':
				octaltodecimal();
				break;	
			case '9':
				sine();	
				break;			
			case '10':
				cosine();
				break;	
			case '11':
				tan();
				break;	
			case '12':
				sec();
				break;	
			case '13':
				cosec();
				break;			
			case '14':
				cot();
				break;	
		*/	default :
				exit(1);
		}
	}
	return 0;
}
	
		








































