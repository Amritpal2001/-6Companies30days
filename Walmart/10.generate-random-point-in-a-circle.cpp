double r, x, y;
Solution(double radius, double x_center, double y_center)
{
    r = radius;
    x = x_center;
    y = y_center;
    srand(time(0));
}

vector<double> randPoint()
{
    vector<double> res;
    double len = sqrt((double)rand() / RAND_MAX) * r;
    double deg = 2 * M_PI * (double)rand() / RAND_MAX;
    res.push_back(x + len * cos(deg));
    res.push_back(y + len * sin(deg));
    return res;
}