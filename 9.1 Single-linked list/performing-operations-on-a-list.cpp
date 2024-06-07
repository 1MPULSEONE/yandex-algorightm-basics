#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int element;
    Node *next;
};

struct Command
{
    int type;
    int x;
    int y;
};

int main()
{
    int q;
    cin >> q;

    Node *head = nullptr;
    vector<Command> commands(q);

    for (int i = 0; i < q; i++)
    {
        int type, x, y;
        cin >> type >> x;
        if (type == 1)
            cin >> y;
        commands[i] = {type, x, y};
    }

    for (const auto &command : commands)
    {
        if (command.type == 1)
        {
            Node *new_node = new Node{command.y, nullptr};
            if (command.x == 0)
            {
                new_node->next = head;
                head = new_node;
            }
            else
            {
                Node *current_node = head;
                for (int i = 1; i < command.x; i++)
                {
                    current_node = current_node->next;
                }
                new_node->next = current_node->next;
                current_node->next = new_node;
            }
        }
        else if (command.type == 2)
        {
            Node *current_node = head;
            for (int i = 1; i < command.x; i++)
            {
                current_node = current_node->next;
            }
            cout << current_node->element << endl;
        }
        else if (command.type == 3)
        {
            if (command.x == 1)
            {
                head = head->next;
            }
            else
            {
                Node *current_node = head;
                for (int i = 1; i < command.x - 1; i++)
                {
                    current_node = current_node->next;
                }
                current_node->next = current_node->next->next;
            }
        }
    }

    return 0;
}