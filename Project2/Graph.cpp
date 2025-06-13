#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // Оскільки граф ненаправлений (Since the graph is undirected)
}

void displayMatrix(vector<vector<int>>& mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    // Треба створити граф з 4 вершинами та без ребер
    // Зауважимо, що всі значення ініціалізуються як 0
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));

    // Тепер додаємо ребра одне за одним
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    /* Альтернативно, ми також можемо створити, використовуючи код нижче,
        якщо ми знаємо всі ребра заздалегідь.

        vector<vector<int>> mat = {{ 0, 1, 0, 0 },
                                  { 1, 0, 1, 0 },
                                  { 0, 1, 0, 1 },
                                  { 0, 0, 1, 0 } }; */

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;
}

//2 спосіб ///

#include <iostream>
#include <vector>
using namespace std;

// Функція для додавання ребра між двома вершинами
void addEdge(vector<vector<int>>& adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i); // Ненаправлений
}

// Функція для відображення списку суміжності
void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": "; // Виведемо вершину
        for (int j : adj[i]) {
            cout << j << " "; // Виведемо її сусіда
        }
        cout << endl;
    }
}

// Головна функція
int main() {
    // Створимо граф з 4 вершинами та без ребер
    int V = 4;
    vector<vector<int>> adj(V);

    // Тепер додаємо ребра одне за одним
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}