#include<stdio.h>
#include<stdlib.h>
struct Poly {
	int coef;
	int expo;
	struct Poly* link;
};typedef struct Poly poly;
poly* newnode(){
	poly* p;
	p = (poly*)malloc(sizeof(poly));
	p->link = NULL;
	return p;
}
poly* readpoly(){
	int ch;
	poly* p = newnode();
	poly* q = p;
	do {
		printf("Enter coef and expo:");
		scanf("%d%d", &p->coef, &p->expo);
		printf("Do you want to enter another term(1:YES 2:NO):");
		scanf("%d", &ch);
		if (ch == 1) {
			p->link = newnode();
			p = p->link;
		}
	} while (ch == 1);
	p->link = NULL;
	return q;
}
poly* addpoly(poly* a, poly* b)
{
	poly* c, * p1, * p2, * p3;
	p1 = a;
	p2 = b;
	p3 = newnode();
	c = p3;
	while (p1 != NULL && p2 != NULL) {
		if (p1->expo == p2->expo) {
			p3->expo = p1->expo;
			p3->coef = p1->coef + p2->coef;
			p1 = p1->link;
			p2 = p2->link;
		}
		else {
			if (p1->expo > p2->expo) {
				p3->coef = p1->coef;
				p3->expo = p1->expo;
				p1 = p1->link;
			}
			else {
				p3->coef = p2->coef;
				p3->expo = p2->expo;
				p2 = p2->link;
			}
		}
		if (p1 != NULL && p2 != NULL) {
			p3->link = newnode();
			p3 = p3->link;
		}
	}
	while (p1 != NULL) {
		p3->link = newnode();
		p3 = p3->link;
		p3->coef = p1->coef;
		p3->expo = p1->expo;
		p1 = p1->link;
	}
	while (p2 != NULL) {
		p3->link = newnode();
		p3 = p3->link;
		p3->coef = p2->coef;
		p3->expo = p2->expo;
		p2 = p2->link;
	}
	p3->link = NULL;
	return c;
}
void main() {
	poly* a, * b, * c;
	printf("Enter first polynomial\n");
	a = readpoly();
	printf("Enter second polynomial\n");
	b = readpoly();
	c = addpoly(a, b);
	printf("Sum of polynomials\n");
	while (c->link != NULL) {
		printf("%dx^%d", c->coef, c->expo);
		c = c->link;
		printf("+");
	}
	printf("%dx^%d", c->coef, c->expo);
}















