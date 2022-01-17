int partition(char nuts[], int l, int h, char pivot)
{
    int i = l;
    for (int j = l; j < h; j++)
    {
        if (nuts[j] < pivot)
        {
            swap(nuts[i], nuts[j]);
            i++;
        }
        else if (nuts[j] == pivot)
        {
            swap(nuts[j], nuts[h]);
            j--;
        }
    }
    swap(nuts[i], nuts[h]);
    return i;
}

void quickSort(char nuts[], char bolts[], int l, int h)
{
    if (l < h)
    {
        int p = partition(nuts, l, h, bolts[h]);
        partition(bolts, l, h, nuts[p]);
        quickSort(nuts, bolts, l, p - 1);
        quickSort(nuts, bolts, p + 1, h);
    }
}

void matchPairs(char nuts[], char bolts[], int n)
{
    // code here
    quickSort(nuts, bolts, 0, n - 1);
}