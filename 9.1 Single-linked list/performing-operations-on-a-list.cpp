#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;

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

    Node *head = nullptr;
    std::vector<Command> commands;

    int type,
        x, y;

    for (int i = 0; i < q;)
    {
        cin >> type >> x >> y;
        Command command = {type, x, y};
        commands.push_back(command);
    }

    for (int i = 0; i < q; i++)
    {
        int type = commands[i].type;
        int x = commands[i].x;
        int y = commands[i].y;

        cout << type << endl;

        if (type == '1')
        {
            if (x == 0)
            {
                Node *newNode = new Node{y, nullptr};
                head = newNode;
            }
            else
            {
                Node *curr = head;
                while (curr->next != nullptr)
                {
                    curr = curr->next;
                }

                Node newNode = {y, nullptr};
                curr->next = curr;
            }
        }

        else if (type == '2')
        {
            Node *curr = head;
            int count = 1;
            while (curr->next != nullptr)
            {
                if (count == x)
                {
                    break;
                }
                curr = curr->next;
                count++;
            }

            cout << curr->next;
        }

        else if (type == '3')
        {
            Node *curr = head;
            int count = 1;
            while (curr->next != nullptr)
            {
                if (count == x - 1)
                {
                    break;
                }
                curr = curr->next;
                count++;
            }

            Node *elemToRemove = curr->next;
            curr->next = elemToRemove->next;
        }

        return 0;
    }
}