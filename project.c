/*	
********* Copyright (C) Suruchi Jadhav. suruchijadhav29@gmail.com
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    ****************************************** */
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
	
	static stack q[MAX], r[MAX];
	stack *add(stack *p, stack *q, int a){
		stack *s1, s, r1;
		s1 = &s;
		int j = 0,sum, carry=0, i;		
		init(&s);
		init(&r1);
		static char sr[MAX];
		
		while(!empty(p) && !empty(q)){
			i = pop(p);
			j = pop(q);
			sum = ( i + j + carry) % 10;
			carry = ( i + j + carry)/10;
			push(sum, &s);
		}
		
		if(empty(p))
			while(!empty(q)){
				i = pop(q);
				sum = (carry + i)%10;
				carry = (carry + i)/10;
				push(sum,&s);
			}
		
		if(empty(q))
			while(!empty(p)){
				i = pop(p);
				sum = (carry + i)%10;
				carry = (carry + i)/10;
				push(sum,&s);
			}

		if(carry!=0){
			push(carry,&s);
		}
		
		if(a==0){
			
			return s1;
		}
		else{
			while(!empty(&s)){
				i = pop(&s);
				push(i, &r1);
			}
			a--;
			add(&r[a+2],&r1,a);
			
			
		}
	
	}		


	stack *multiply(stack *p, stack *l, int a, int b){
		int i, j = 0, k = 0, m, n, t = 0;
		
		char str1[MAX], str2[MAX];
		int a1[MAX], a2[MAX], carry = 0, mul=0,count;
		
		stack *res1 , r[MAX], q[MAX], q2;
		stack rev1, rev2;
		m = b;
		n = a;	
		
		while(k!=MAX){
			init(&q[k]);
			k++;
		}
		
 		k = 0;
		
		while(k!=MAX){
			init(&r[k]);
			k++;
		}					
		
		a = 0;
		while(!empty(p)){
			i = pop(p);
			a1[a] = i;
			a++;
		}
		a--;
		b = 0;
		while(!empty(l)){
			i = pop(l);
			a2[b] = i; 			 
			b++;
		}
		b--;
		count = m;
		i = 0;
		
		
		for(i = 0; i<=b; i++){		
			k = t;
			carry = 0;
			for(j = 0; j<=a; j++){
			
				
				if(t == 0){
					mul = (a2[i]*a1[j] + carry)%10; 		
					carry = (a2[i]*a1[j] + carry)/10;
					push(mul, &q[t]);
				}
				else{
					
					while(k>0){
						mul = 0;
						push(mul, &q[t]);
						k--;
					}
					
					mul = (a2[i]*a1[j] + carry)%10; 
					carry = (a2[i]*a1[j] + carry)/10;
					push(mul, &q[t]);
				}
			}
			if(carry!=0){
				push(carry, &q[t]);
			}		
			t++;
		}
		t--;
		k = t;					
		
		while(t>=0){
			
			
			while(!empty(&q[t])){
				mul = pop(&q[t]);
				push(mul, &r[t]);
			}
			
			t--;
		}
		
		if(k == 0){
			
			res1 = &q2;
			while(!empty(&r[0])){
				k = pop(&r[0]);
				push(k, &q2);
			}
			
				return res1;
		}

			t = k - 1;
			res1 = add(&r[0], &r[1], t);			
			return res1;		
	
	}



	stack *subtract(stack *p, stack *q){
			int n1, n2;
			stack *u;
			stack s;
			init(&s);
			u = &s;
			int sub;
		
			n1 = pop(p);
			n2 = pop(q);
		while(!empty(p) && !empty(q)){
			
			if(n1 < n2){
				n1 = n1 + 10;
				sub = n1 - n2;
				push(sub, &s);
				n1 = n1 - 10;
			}
			else{
				sub = n1 - n2;
				push(sub, &s);
			}
			if(n1 < n2){
				n1 = pop(p);
				
				n1 = n1 - 1;
				n2 = pop(q);
			}
			else{
				n1 = pop(p);
				n2 = pop(q);
			}
		}
		if(n1 < n2){
				n1 = n1 + 10;
				sub = n1 - n2;
				push(sub, &s);
			}
			else{
				sub = n1 - n2;
				push(sub, &s);
			}
		if(empty(p)){
			while(!empty(q)){
			sub = pop(q);
			push(sub, &s);
			}
			sub = pop(&s);
			
			push(sub,&s);
			
			return u;
		}
		
		if(empty(q)){
			
			while(!empty(p)){
			sub = pop(p);
			push(sub, &s);
			}
			
			
			return u;
		}
		
		return u;
			

	}
	
	stack  *division(stack *p, stack *q){
		int i = 0, count = 1, j= 0;		
		stack u[MAX];

		while(i!=MAX){
			init(&u[i]);
			i++;
		}
	
		stack s, o;
		init(&s);
		init(&o);

		stack *r;
		r = &o;		

		while(!empty(p)){
			i = pop(p);
			push(i, &s);
		}
		
		while(!empty(&s)){
			i = pop(&s);
			push(i, &o);
		}
	
		while(1){ //till divider is smaller than dividend
			while(!empty(r)){
				r = subtract(r, q);
				count++;	 
				push(count, &u[j]);
			}
			j++;
		}
		
	}	

		
	void decimaltobinary(){
	
		char str[MAX];
		int k, j=0, count, i=0, t=1, num, div, o=0;
		stack bin;
		queue q[MAX];
		scanf("%s",str);
		init(&bin);
	
		while(o!=MAX){
			qinit(&q[o]);
			o++;
		}

		while(str[j] != '\0'){
			num = str[j] - '0';
			enqueue(num, &q[0]);
			j++;
		}	
		
		while(1){					  																																																														
			t = 1;
			while(!qempty(&q[i])){
				j = dequeue(&q[i]); 
				if(j == 1){
					j = 10+ dequeue(&q[i]);
				}
				k = t * j;
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
				i++;
		}

			
				while(!empty(&bin)){
					printf("%d",pop(&bin));
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
	
	int isoperator(char c){
		if(c == '+' || c == '-' || c == '*' || c == '/')
			return 1;
		else 		
			return 2;
	}


int main(){
	char *c, str[MAX], ch[MAX];
			
	stack m1, m2, m3, m4, z[MAX];
	
	stack d;
	scanf("%s",str);
	int i=0, j=0, m, size[MAX], k=1, i1=0;	
	stack *r; 
	
	while(i!=MAX){
		init(&z[i]);
		i++;
	}
				
	i = 0;
	init(&m1);
	init(&m2);
	init(&m3);
	init(&m4);
	init(&d);						
	if(str[i]=='b'){
		decimaltobinary();
		return 0;
	}
	if(str[i]=='o'){
		decimaltooctal();
		return 0;
	}
	
	else{			
	while(str[i]!='\0'){
			
		if(isoperator(str[i])==2){
			m = str[i] - '0';		
			push(m, &z[j]);		
			i++;
			k++;
		}			

		else{
			size[j] = k - 2; 
							
			j++;
			i++;
			k = 1;
		}
	}
								
	size[j] = k - 2;		
	i = 0;
	j = 0;

	while(str[j]!='\0'){

		if(isoperator(str[j])==1){
			ch[i] = str[j];			
			i++;	
			j++;
		}
		else
			j++;
	}
	
	i = 0;
	
	while(ch[i]!='\0'){
		if(ch[i] == '*')
			push(i+1,&m1);
		if(ch[i] == '+')
			push(i+1, &m2);			
			
		if(ch[i] == '-')
			push(i+1, &m3);

		if(ch[i] == '/')

			push(i+1, &m4);
		i++;
	}

	j = i;
						
	while(!empty(&m1)){
		i = pop(&m1);			
		if(!empty(&z[i-1]) && !empty(&z[i]))
			r = multiply(&z[i-1], &z[i], size[i - 1], size[i]);			
		else						
			r = multiply(&z[i-2], &z[i], size[i -2], size[i]);

		while(!empty(r)){
			i1 = pop(r);
			push(i1, &z[i-1]);
		}	
	}	

	while(!empty(&m2)){
		i = pop(&m2);							
		if(!empty(&z[i-1]) && !empty(&z[i]))
			r = add(&z[i-1], &z[i], 0);
								
		else
			r = add(&z[i-2], &z[i], 0);

		while(!empty(r)){
			i1 = pop(r); 						
			push(i1, &z[i-1]);					
		}	
	}   
	
	while(!empty(&m3)){
		i = pop(&m3);							
		if(!empty(&z[i-1]) && !empty(&z[i]))
			r = subtract(&z[i-1], &z[i]);
								
		else
			r = subtract(&z[i-2], &z[i]);

		while(!empty(r)){
			i1 = pop(r); 								
			push(i1, &z[i-1]);						
		}	
	}   
	

	while(!empty(&m4)){
		i = pop(&m4);							
		if(!empty(&z[i-1]) && !empty(&z[i]))
			r = division(&z[i-1], &z[i]);
								
		else
			r = division(&z[i-2], &z[i]);
		while(!empty(r)){
			i1 = pop(r); 								
			push(i1, &z[i-1]);						
		}	
	}   

	i = 0;

	while(1){
		if(!empty(&z[i])){						

			while(!empty(&z[i])){
				k = pop(&z[i]);
				push(k, &d);			
			}

			while(!empty(&d)){
				printf("%d",pop(&d));	
			}

			return 0;
		}								
		i++;	
	}

	return 0;

	}

	return 0;

}





































