#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

struct node
{
    int info;
    struct node *link;
};

struct arr
{
    int p;
    int q;
} ar[20];

typedef struct node *NODE;
static NODE first = NULL;
static int count = 0, flag = 1;

int choice, item, key;
float color[4][3] = {
    {1.0, 1.0, 1.0},
    {0.8, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.8}};

void PrintString(float x, float y, char *string, int col)
{
    char *c;
    glColor3fv(color[col]);
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}

void Title()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    PrintString(200.0, 450.0, "SINGLY LINKED LIST", 1);
    PrintString(50.0, 350.0, "NAME: SWAROOP D", 3);
    PrintString(50.0, 300.0, "University Number: 1BG11CS110", 3);
    PrintString(50.0, 100.0, "COLLEGE: BNMIT", 3);
    PrintString(150.0, 50.0, "(Click right mouse button for options)", 2);
    glFlush();
}

void delay()
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            ;
}

void delay1()
{
    int i, j;
    for (i = 0; i < 50000; i++)
        for (j = 0; j < 50000; j++)
            ;
}

void IntroDelay()
{
    if (flag)
    {
        int d = 10;
        Title();
        while (d > 0)
        {
            delay();
            d--;
        }
        flag = 0;
    }
    glClear(GL_COLOR_BUFFER_BIT);
}

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void EmptyList()
{
    glColor3f(0.5, 0.4, 0.7);
    PrintString(250, 250, "Empty list", 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(50, 200);
    glVertex2i(50, 250);
    glVertex2i(130, 250);
    glVertex2i(130, 200);
    glEnd();
    glFlush();
}

void PrintString1(float x, float y, char *string, int col)
{
    char *c;
    glColor3fv(color[col]);
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
}

void display()
{
    int i = 0, j = 0, k = 0, b[20];
    NODE temp;
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.6);
    PrintString(200.0, 450.0, "SINGLY LINKED LIST", 1);
    if (first == NULL)
    {
        printf("List is empty\n");
        EmptyList();
        return;
    }
    printf("Contents of singly linked list \n");
    temp = first;
    while (temp != NULL)
    {
        for (k = 0; k < count; k++)
        {
            GLfloat x1 = 50, x2 = 80, x3 = 110, y1 = 200, y2 = 225, y3 = 250, x4 = 95, y4 = 225, x5 = 160, y5 = 210, y6 = 240, x6 = 180;
            if (first->link == NULL)
            {
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINES);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x3 + k * 130, y1);
                glEnd();
            }

            if (temp->link == NULL)
            {
                glColor3f(1.0, 0.0, 0.0);
                glBegin(GL_POLYGON);
                glVertex2i(x1 + k * 130, y1);
                glVertex2i(x1 + k * 130, y3);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x2 + k * 130, y1);
                glEnd();
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_POLYGON);
                glVertex2i(x2 + k * 130, y1);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x3 + k * 130, y3);
                glVertex2i(x3 + k * 130, y1);
                glEnd();
                glColor3f(1.0, 1.0, 1.0);
                glBegin(GL_LINES);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x3 + k * 130, y1);
                glEnd();
                glBegin(GL_LINES);
                glVertex2i(x2 + k * 130, y1);
                glVertex2i(x3 + k * 130, y3);
                glEnd();
            }
            else
            {
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINES);
                glVertex2i(x4 + k * 130, y4);
                glVertex2i(x6 + k * 130, y4);
                glEnd();
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINES);
                glVertex2i(x5 + k * 130, y6);
                glVertex2i(x6 + k * 130, y4);
                glVertex2i(x6 + k * 130, y4);
                glVertex2i(x5 + k * 130, y5);
                glEnd();
                glColor3f(1.0, 0.0, 0.0);
                glBegin(GL_POLYGON);
                glVertex2i(x1 + k * 130, y1);
                glVertex2i(x1 + k * 130, y3);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x2 + k * 130, y1);
                glEnd();
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_POLYGON);
                glVertex2i(x2 + k * 130, y1);
                glVertex2i(x2 + k * 130, y3);
                glVertex2i(x3 + k * 130, y3);
                glVertex2i(x3 + k * 130, y1);
                glEnd();
            }
            b[j] = temp->info;
            printf("%d", temp->info);
            temp = temp->link;
            printf("\n");
            ar[i].p = b[j] / 10;
            ar[i].q = b[j] % 10;
            ar[i].p = ar[i].p + 48;
            ar[i].q = ar[i].q + 48;
            glColor3f(1.0, 1.0, 0.0);
            glRasterPos2f(60.0 + k * 130, 225.0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ar[i].p);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ar[i].q);
            PrintString1(50.0 + k * 130, 185, "INFO", 1);
            PrintString1(85.0 + k * 130, 185, "LINK", 1);
            i++;
            j++;
            glFlush();
        }
    }
}

NODE GetNode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Insufficient memory \n");
        exit(0);
    }
    return x;
}

NODE InsertFront(int item, NODE first)
{
    NODE temp;
    temp = GetNode();
    temp->info = item;
    temp->link = first;
    return temp;
}

NODE InsertRear(int item, NODE first)
{
    NODE temp;
    NODE cur;
    temp = GetNode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = temp;
    return first;
}

NODE InsertSpecified(int item, NODE first)
{
    NODE next, cur, temp;
    temp = GetNode();
    temp->info = item;
    if (first == NULL)
    {
        printf("List is empty.inserting node at front end...\n");
        temp->link = NULL;
        first = temp;
        return first;
    }
    printf("Enter the key : ");
    scanf("%d", &key);
    cur = first;
    while (cur != NULL)
    {
        next = cur->link;
        if (cur->info == key)
        {
            printf("Key found\n");
            cur->link = temp;
            temp->link = next;
            return first;
        }
        cur = cur->link;
    }
    if (cur == NULL)
    {
        printf("Search unsuccessful\n");
        count--;
    }
    return first;
}

NODE DeleteFront(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty cannot delete\n");
        EmptyList();
        count++;
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("Item deleted=%d \n", first->info);
    free(first);
    return temp;
}

NODE DeleteRear(NODE first)
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("List is empty cannot delete \n");
        EmptyList();
        count++;
        return first;
    }
    if (first->link == NULL)
    {
        printf("Item to be deleted is %d \n", first->info);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Item deleted is %d \n", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}

NODE DeleteSpecified(NODE first)
{
    NODE prev, cur;
    if (first == NULL)
    {
        printf("List is empty\n");
        EmptyList();
        count++;
        return NULL;
    }
    printf("Enter the key");
    scanf("%d", &key);
    if (key == first->info)
    {
        cur = first;
        first = first->link;
        free(cur);
        return first;
    }
    prev = NULL;
    cur = first;
    while (cur != NULL)
    {
        if (key == cur->info)
            break;
        prev = cur;
        cur = cur->link;
    }
    if (cur == NULL)
    {
        printf("Search is unsuccessful\n");
        count++;
        return first;
    }
    prev->link = cur->link;
    free(cur);
    return first;
}

void SLLmenu(int choice)
{
    switch (choice)
    {
    case 1:
        printf("\nEnter the item to be inserted\n");
        scanf("%d", &item);
        first = InsertFront(item, first);
        count++;
        display();
        break;
    case 2:
        printf("\nEnter the item to be inserted\n");
        scanf("%d", &item);
        first = InsertRear(item, first);
        count++;
        display();
        break;
    case 3:
        printf("\nEnter the item to be inserted: ");
        scanf("%d", &item);
        first = InsertSpecified(item, first);
        count++;
        display();
        break;
    case 4:
        first = DeleteFront(first);
        count--;
        display();
        break;
    case 5:
        first = DeleteRear(first);
        count--;
        display();
        break;
    case 6:
        first = DeleteSpecified(first);
        count--;
        display();
        break;
    case 7:
        exit(0);
    }
}

void main(int argc, char **argv)
{
    printf(" SINGLY LINKED LIST \n\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(300, 0);
    delay1();
    glutCreateWindow("SINGLY LINKED LIST");
    glutCreateMenu(SLLmenu);
    glutAddMenuEntry("Insert Front", 1);
    glutAddMenuEntry("Insert Rear", 2);
    glutAddMenuEntry("Insert Specified", 3);
    glutAddMenuEntry("Delete Front", 4);
    glutAddMenuEntry("Delete Rear", 5);
    glutAddMenuEntry("Delete Specified", 6);
    glutAddMenuEntry("Exit", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(IntroDelay);
    init();
    glutMainLoop();
}