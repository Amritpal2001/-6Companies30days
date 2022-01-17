void linkdelete(struct Node *head, int M, int N)
{
    //Add code here
    while (head)
    {
        int m = M - 1, n = N;
        while (head && m--)
            head = head->next;
        if (head == NULL || head->next == NULL)
            return;
        Node *temp = head->next;
        while (temp && n--)
            temp = temp->next;
        head->next = temp;
        head = temp;
    }
}