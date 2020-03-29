//all subsets which contain 1 in s

for (int s = x ; ; s = (s - 1) & x) {
    cout<<s<<endl;
	if (s == 0) break;
}