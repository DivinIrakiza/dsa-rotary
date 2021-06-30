#include<iostream>
#include "file-handler.h"
#include "package.h"
using namespace std;

char *FILENAME = "software-store.txt";

    File file(FILENAME);

class SoftwareStore {
    struct node {
        StoreItem* storeItem;
        node* left;
        node* right;
    };

    node* root;

    node* empty(node* t) {
        if(t == NULL)
            return NULL;
        {
            empty(t->left);
            empty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(StoreItem* item, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->storeItem->name = item->name;
            t->storeItem->version = item->version;
            t->storeItem->quantity = item->quantity;
            t->storeItem->price = item->price;

            t->left = t->right = NULL;
        }
        else if(item->quantity < t->storeItem->quantity)
            t->left = insert(item, t->left);
        else if(item->quantity > t->storeItem->quantity)
            t->right = insert(item, t->right);


        cout <<  "sdf" << endl;
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(StoreItem* item, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(item->quantity < t->storeItem->quantity)
            t->left = remove(item, t->left);
        else if(item->quantity > t->storeItem->quantity)
            t->right = remove(item, t->right);
        else if(t->left && t->right){
            temp = findMin(t->right);
            t->storeItem->quantity = temp->storeItem->quantity;
            // t->right = remove(t->storeItem->quantity, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        string output = "";
        output.append(t->storeItem->name + "\t\t");
        output.append(t->storeItem->version + "\t\t");
        output.append(t->storeItem->quantity + "\t");


        cout << output << " ";
        inorder(t->right);


    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->storeItem->quantity)
            return find(t->left, x);
        else if(x > t->storeItem->quantity)
            return find(t->right, x);
        else
            return t;
    }

public:
    SoftwareStore() {
        root = NULL;
    }

    ~SoftwareStore() {
        root = empty(root);
    }

    void insert(StoreItem* item) {
        root = insert(item, root);
    }

    void remove(StoreItem* item) {
        root = remove(item, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }
};

int main() {
    SoftwareStore t;
    // file.read();

    StoreItem item1 = {"Adobe Photoshop", "CS5", 21, 580};
    StoreItem item2 = {"Adobe Photoshop", "CS5", 121, 580};
    StoreItem item3 = {"Adobe Photoshop", "CS5", 11, 580};
    
    t.insert(&item1);
    
    t.display();



    return 0; 
}