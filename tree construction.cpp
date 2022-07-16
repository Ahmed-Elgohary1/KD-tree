#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class point
{
public:
    double x, y;
};

class node:public point
{
public:
    node* left, * right;
};

class nn:public point
{
public:
    double nndist;
};



//Those are  helper functions that helps our code to be organized.
void merg(int a[][2], int l, int mid, int r, int level, int dimension);
void mergesort(int arr[][2], int l, int r, int level, int dimension);
double  distance(node* CurrentNode, point target);
int compare(node* currentnode, point target, int parmtr);
int SplitDist(node* currentnode, point target, int parmtr);


//Those are  main functions.
void constr(int points[][2], int l, int r, node* parent, int level)
{
    mergesort(points, l, r, level % 2, 2);

    int mid = (r + l) / 2;
    parent->x = points[mid][0];
    parent->y = points[mid][1];
    if (r >= l)level++;
    if (l <= mid - 1)
    {
        parent->left = new node();
        constr(points, l, mid - 1, parent->left, level);
    }
    if (mid + 1 <= r)
    {
        parent->right = new node();
        constr(points, mid + 1, r, parent->right, level);

    }
}
int searching(node* parent, int x, int y)
{
    int level = 0;
    while (parent != NULL)
    {
        if (x == parent->x && y == parent->y)
            return 1;
        if ((x < parent->x) || ((y < parent->y) && (level % 2)))
        {
            parent = parent->left;
            // cout<<parent->x<<"  "<<parent->y<<endl;

        }
        else
        {
            parent = parent->right;
            // cout<<parent->x<<"  "<<parent->y<<endl;
        }
        level++;
    }
    return -1;
}
void inserting(node* parent, int x, int y)
{
    int level = 0;
    while (parent != NULL)
    {
        if (x == parent->x && y == parent->y)
            return;
        if ((x < parent->x) || ((y < parent->y) && (level % 2)))
        {
            parent = parent->left;
        }
        else
        {
            parent = parent->right;
        }
        level++;
       if (parent->left == NULL && parent->right == NULL)break;
    }
    if (parent)//to solve dereferencing NULL pointer warrning
    {
        node* temp{};
        if ((x < parent->x) || ((y < parent->y) && (level % 2)))
            temp = parent->left = new node();
        else
            temp = parent->left = new node();

        temp->x = x;
        temp->y = y;
        
    }
}
//Finds the closest point to a given target. We also pass  the best values found so far for nearest neighbor (NN) 
//and its distance to help pruning. These values default  to null, infinity for a call on the tree root.
nn nearestNeighbor(node* CurrentNode, point Target, nn NearestNode,int level)
{
    node* CloseBranch, *FarBranch;
    //cout << NearestNode.nndist<<endl;
    if (CurrentNode == NULL)
        return NearestNode;
            /*                                        we have three tasks :
                                                    check if the current node is closer
                                                        than previously found NN, traverse
                                                        the branch on the same side of the
                                                        split with respect to the target
                                                        point, and check if we can prune the
                                                        other branch(or traverse it as well).*/
    else
    {
       double dist= distance(CurrentNode,Target);
       if (dist < NearestNode.nndist)
       {
               /*                                        If that distance is less than the current
                                                       NN’s distance, we have to update the
                                                       values stored for the NNand its distance.*/
           NearestNode.nndist = dist;
           NearestNode.x = CurrentNode->x;
           NearestNode.y = CurrentNode->y;
       }
                                                      /* We certainly need to traverse the closest branch
                                                       in search of the nearest neighbor.It is important
                                                       to do so firstand update the mementos for NN’s
                                                       distance, to improve pruning.*/
           if (compare(CurrentNode, Target, level % 2) < 0)
               {
                   CloseBranch = CurrentNode->left;
                   FarBranch = CurrentNode->right;
               }
               else
               {
                   CloseBranch = CurrentNode->right;
                   FarBranch = CurrentNode->left;
               }
       NearestNode = nearestNeighbor(CloseBranch, Target, NearestNode, ++level);
       if(SplitDist(CurrentNode,Target,level%2)< NearestNode.nndist)//Traverses the furthest branch and updates the current values for NN and its distance
           NearestNode = nearestNeighbor(FarBranch, Target, NearestNode, ++level);

    }
    return NearestNode;
}

void NeighborsInRange(node* CurrentNode, point Target,double raduis, vector<point>& SurroundingPoints, int level)
{
    node* CloseBranch, * FarBranch;
    point Surrounded{};
    if (CurrentNode == NULL)
        return;
    
    else
    {
        double dist = distance(CurrentNode, Target);
        Surrounded.x = CurrentNode->x; Surrounded.y = CurrentNode->y;
        if (dist < raduis)
        {
            
            SurroundingPoints.push_back(Surrounded);
        }
   
        if (compare(CurrentNode, Target, level % 2) < 0)
        {
            CloseBranch = CurrentNode->left;
            FarBranch = CurrentNode->right;
        }
        else
        {
            CloseBranch = CurrentNode->right;
            FarBranch = CurrentNode->left;
        }
        NeighborsInRange(CloseBranch, Target,raduis,SurroundingPoints, ++level);
        if (SplitDist(CurrentNode, Target, level % 2) < raduis)
            NeighborsInRange(FarBranch, Target, raduis,SurroundingPoints, ++level);

    }
    return ;
}





void print(node* head);


int main()
{
    //sample of points in 2d 
    int points[][2] = { {3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19} };

    node* head = new node();
    nn nearstnode{}, pop{};
    nearstnode.nndist = 30000;
   nearstnode.x = 30000;nearstnode.y = 30000;

    constr(points, 0, 6, head, 0);
    /*inserting(head, -1, 15);
    cout<<searching(head,-1,15);*/
    vector<point>SurroundingPoints, solution;

    point targ{};
    targ.x = 14;
    targ.y = 15;
    /*NeighborsInRange(head, targ, 10, SurroundingPoints, 0);
    for (int i = 0; i < SurroundingPoints.size(); i++)
        cout << SurroundingPoints[i].x << "  " << SurroundingPoints[i].y << endl;*/

    //pop=nearestNeighbor(head,targ , nearstnode, 0);
    //cout << pop.x<<"  "<<pop.y;
    //print(head);
}

//print the tree by traversing it in preorder.
void print(node* head)
{
    if (head == NULL)return;
    cout << head->x << "  " << head->y << endl;
    print(head->left);

    print(head->right);

}




// Merge two subarrays Left and right into array "a"
void merg(int a[][2], int l, int mid, int r, int level, int dimension)
{
    int n1 = mid - l + 1, n2 = r - mid;

    // Create Left ← a[l..mid] and right ← a[mid+1..r]
    int** left = new int* [n1],
        ** right = new int* [n2];
    for (int i = 0; i < n1; i++)
        left[i] = new int[dimension];
    for (int i = 0; i < n2; i++)
        right[i] = new int[dimension];

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < dimension; j++)
            left[i][j] = a[l + i][j];

    for (int i = 0; i < n2; i++)
        for (int j = 0; j < dimension; j++)
            right[i][j] = a[mid + 1 + i][j];

    // Maintain current index of sub-arrays and main array
    int i = 0, k = l, j = 0;
    // Until we reach either end of either Left or right , pick larger among
      // elements Left and right and place them in the correct position at A[l..r]
    while (i < n1 && j < n2)
    {
        if (left[i][level] <= right[j][level])
        {
            for (int ite = 0; ite < dimension; ite++)
                a[k][ite] = left[i][ite];
            i++;
        }
        else
        {
            for (int ite = 0; ite < dimension; ite++)
                a[k][ite] = right[j][ite];
            j++;
        }
        k++;
    }

    // When we run out of elements in either Left or right,
      // pick up the remaining elements and put in A[l..r]
    while (i < n1)
    {
        for (int ite = 0; ite < dimension; ite++)
            a[k][ite] = left[i][ite];
        i++;
        k++;
    }

    while (j < n2) {
        for (int ite = 0; ite < dimension; ite++)
            a[k][ite] = right[j][ite];
        j++;
        k++;
    }



    //demolish the temporary containers left and right
    for (int i = 0; i < n1; i++)
        delete left[i];
    delete[] left;
    for (int i = 0; i < n2; i++)
        delete right[i];
    delete [] right;

}



// Divide the array into two subarrays, sort them and merge them
void mergesort(int arr[][2], int l, int r, int level, int dimension)
{
    if (l < r)
    {
        // mid is the point where the array is divided into two subarrays
        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid, level, dimension);
        mergesort(arr, mid + 1, r, level, dimension);
        // Merge the sorted subarrays
        merg(arr, l, mid, r, level, dimension);

    }

}
//We compute the distance between the current node’s pointand target.
double  distance(node* CurrentNode, point target)
{
    double dist;
    dist = sqrt(pow((CurrentNode->x - target.x), 2) + pow((CurrentNode->y - target.y), 2));
    return dist;

}

                                        //Checks if the target point is on the left branch of
                                        //the split.If it is, the left branch is the closest to
                                        //the target point, otherwise it is the furthest.

int compare(node* currentnode, point target, int parmtr)
{
    switch (parmtr)
    {
    case 0:
        if (target.x <= currentnode->x)
            return -1;
        else
            return 1;
        break;
    case 1:
        if (target.x <= currentnode->x)
            return -1;
        else
            return 1;
        break;
    }
    return 0;
}
                                        //we compute the distance between the
                                        //split line passing through the current nodeand
                                        //the target point.If this distance is closer than the
                                        //distance to current nearest neighbor, then the
                                        //furthest branch might contain points closer than
                                        //the current nearest neighbor
int SplitDist(node* currentnode, point target, int parmtr)
{
    switch (parmtr)
    {
    case 0:
        return abs(target.x - currentnode->x);

        break;
    case 1:
        return abs(target.y - currentnode->y);
        break;
    }
    return 0;
}
