#include <iostream>

using namespace std;

struct nums
{
    char number;
    nums *left;
    nums *right;
};

void initializenums(nums *&, int &, int &);
void add(nums *, nums *);
void subtract(nums *, nums *);
void output(nums *, int);

int main()
{
    char operators;
    int a, b, n;
    int c1, c2, c3;
    nums *head1, *head2, *t, *p, *q;
    cout << "Please enter two long integers in a comma-separated manner by 1 group of each of the 3 digits, and press Enter for each input to indicate that the input is complete: " << endl;
    initializenums(head1, a, c1);
    initializenums(head2, b, c2);
    cout << endl;
    cout << "Please select the operation that needs to be performed, type + to add, type - to subtract (Please press enter after selecting the operation): ";
    cin >> operators;
    cout << "The result of the run is: ";
    switch (operators){
    case '+':
        c3 = 0;
        break;
    case '-':
        c3 = 1;
        break;
    default:
        cout << "error" << endl;
        return 0;
    }
    c2 = c2 + c3;
    if (c2 == 2){
        c2 = 0;
    }
    if (b > a){
        t = head1;
        head1 = head2;
        head2 = t;
        n = a;
        a = b;
        b = n;
        n = c1;
        c1 = c2;
        c2 = n;
    }
    while (a > b)
    {
        t = new nums;
        t -> number = '0';
        t -> left = nullptr;
        t -> right = head2;
        head2 -> left = t;
        head2 = t;
        b = b + 1;
    }
    if (c1 == 0 && c2 == 0){
        add(head1, head2);
    }
    else if (c1 == 1 && c2 == 1){
        cout << "-";
        add(head1, head2);
    }
    else{
        if (a == b){
            p = head1;
            q = head2;
            while(p->number == q->number && p->right != nullptr){
                p = p->right;
                q = q->right;
            }
            if(p->number == q->number){
                cout << "0" << endl;
                return 0;
            }
            if(q->number > p->number){
                t = head1;
                head1 = head2;
                head2 = t;
                n = c1;
                c1 = c2;
                c2 = n;
            }
        }
        if(c1 == 1){
            cout << "-";
        }
        subtract(head1, head2);
    }
    output(head1, a+1);
    system("pause");
}

void initializenums(nums *&head, int &n, int &m)
{
    char c;
    nums *s, *p;
    n = 0;
    s = new nums;
    c = getchar();
    head = nullptr;
    if(c == '-'){
        m = 1;
        c = getchar();
    }
    else{
        m = 0;
    }
    while(c != '\n'){
        if(c == ','){
            c = getchar();
            continue;
        }
        s->number = c;
        if(head == nullptr){
            head = s;
            head->left = nullptr;
            head->right = nullptr;
            p = head;
        }
        else{
            s->left = p;
            s->right = nullptr;
            p->right = s;
            p = s;
        }
        n = n+1;
        s = new nums;
        c = getchar();
    }
    delete s;
    p = new nums;
    p->number = '0';
    p->left = nullptr;
    p->right = head;
    head->left = p;
    head = p;
}

void add(nums *head1, nums *head2)
{
    nums *p, *q;
    int a, b, m, t;
    p = head1;
    q = head2;
    while(p->right != nullptr){
        p = p->right;
    }
    while(q->right != nullptr){
        q = q->right;
    }
    m = 0;
    do{
        a = p->number - '0';
        b = q->number - '0';
        t = a + b + m;
        m = t / 10;
        t = t % 10;
        p->number = '0' + t;
        p = p->left;
        q = q->left;
    } while(q != nullptr);
}

void subtract(nums *head1, nums *head2)
{
    nums *p, *q;
    int a, b, t, m;
    p = head1;
    q = head2;
    while (p->right != nullptr){
        p = p->right;
    }
    while (q->right != nullptr){
        q = q->right;
    }
    m = 0;
    while(q != nullptr){
        a = p->number - '0';
        b = q->number - '0';
        t = a - b + m;
        if(t < 0 && p->left != nullptr){
            m = -1;
            t = t + 10;
        }
        else{
            m = 0;
        }
        p->number = '0' + t;
        p = p->left;
        q = q->left;
    }
}

void output(nums *head, int a)
{
    nums *s;
    s = head;
    while(s->number == '0' && s->right != nullptr){
        s = s->right;
        a = a-1;
    }
    if(s->number == '0'){
        cout << "0" << endl;
        return;
    }
    while(s->right != nullptr){
        cout << s->number;
        a = a-1;
        if(a%3 == 0 && a != 0){
            cout << ",";
        }
        s = s->right;
    }
    cout << s->number;
    cout << '\n';
}

