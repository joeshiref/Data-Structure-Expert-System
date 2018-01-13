#include "ExpertDS.h"

void ExpertDS::memory_important()
{
	cout << "Is Memeory Important? :";
	cin >> choice;
	if (choice == 'Y')
	{
		add_remove();
	}
	else
	{
		cout << "Then the most effiecent data strucutre is : Tries" << endl;
		ll_tire x;
		cout << "Enter 5 elements" << endl;
		long long in;
		for (int i = 0; i < 5; i++)
		{
			cin >> in;
			x.insert(in);
		}
		cout << "count frequancy of specific element : ";
		cin >> in;
		x.del(in);
		cout << x.get_freq(in) << endl;

	}
}
void ExpertDS::key_value()
{
	cout << "Will be there key/value ? :";
	cin >> choice;
	if (choice == 'Y')
	{
		cout << "Then the most effiecent data strucutre is : Hash Table" << endl;
		Unordered_map<string, int>mp;
		string k;
		int v;
		cout << "Enter 3 elements in the data structure to test it" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "Enter key :";
			cin >> k;

			cout << "Enter value :";
			cin >> v;

			mp.insert(k, v);
		}
		cout << "Enter Key to get the value :";
		cin >> k;
		cout << "Value is :";
		cout << mp.Get(k) << endl;
		cout << "Enter element with an old key" << endl;
		cout << "Enter key :";
		cin >> k;
		cout << "Enter value :";
		cin >> v;
		mp.insert(k, v);
		cout << "Value is :";
		cout << mp.Get(k) << endl;
	}
	else
	{
		cout << "Then the most effiecent data strucutre is : AVL tree " << endl;
		AVL_tree<int>B;
		cout << "Enter 10 elements" << endl;
		int x;
		for (int i = 0; i < 10; i++)
		{
			cin >> x;
			B.add(x);
		}
		cout << "Elements in the tree :" << endl;
		B.preOrder(B.root);
		cout << "Enter element to be deleted :";
		cin >> x;
		B.del(x);
		cout << "Elements in the tree :" << endl;
		B.preOrder(B.root);
	}
}
void ExpertDS::middle()
{
	cout << "will be there access in middle ? :";
	cin >> choice;
	if (choice == 'Y')
	{
		key_value();
	}
	else
	{
		cout << "Data will be last in , first out? : ";
		cin >> choice;
		if (choice == 'Y')
		{
			cout << "Then the most effiecent data strucutre is : Stack" << endl;
			Stack<int>st;
			cout << "Enter 3 numbers" << endl;
			int x;
			cin >> x;
			st.push(x);
			cin >> x;
			st.push(x);
			cin >> x;
			st.push(x);
			cout << "Last element : " << st.top() << endl;

		}
		else
		{
			cout << "Then the most effiecent data strucutre is : Queue" << endl;
			Queue<int>st;
			cout << "Enter 3 numbers" << endl;
			int x;
			cin >> x;
			st.push(x);
			cin >> x;
			st.push(x);
			cin >> x;
			st.push(x);
			cout << "Last element : " << st.front() << endl;
		}
	}
}

void ExpertDS::add_remove()
{
	cout << "Will be there alot of add/remove ? :";
	cin >> choice;
	if (choice == 'Y')
	{
		middle();
	}
	else
	{
		cout << "Then the most effiecent data structure is : Vector" << endl;
		Vector<int>v;
		int x;
		cout << "Enter 3 numbers to test your data structure" << endl;
		for (int i = 0; i < 3; i++)
		{
			cin >> x;
			v.push_back(x);
		}
		cout << "numbers you have entered : ";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v.at(i) << " ";
		}
		cout << endl;
	}
}
ExpertDS::ExpertDS()
{
	apply_functions();
}
void ExpertDS::apply_functions()
{
	cout << "Are you going to apply functions on data structure? :";
	cin >> choice;
	if (choice == 'Y')
		immutable();
	else {
		memory_important();
	}
}
void ExpertDS::immutable()
{
	cout << "Is data immutable? :";
	cin >> choice;
	cout << endl;
	if (choice == 'Y')
	{
		cout << "Then the most effiecent data structure is : Sparse table" << endl;
		int n;
		cout << "Enter the size of elements :";
		cin >> n;
		int *arr = new int[n + 1];
		for (int i = 0; i<n; i++)
			cin >> arr[i];
		sparse_table sparse(arr, n);
		int f, l;
		cout << "Enter your interval :" << endl;
		cout << "Start :";
		cin >> f;
		cout << "End :";
		cin >> l;
		f--, l--;
		cout << "Minimum of this interval :";
		cout << sparse.minimum(f, l, arr) << endl;
	}
	else
	{
		cout << "Then the most effiecent data structure is : Segment tree" << endl;
		cout << "There are 3 types of segment tree , which one you want to use ? :" << endl;
		cout << "1- Sum on interval" << endl;
		cout << "2- Mimimum value on interval" << endl;
		cout << "3- Maximum value on interval" << endl;
		cout << "Enter Your Choice : ";
		cin >> enter;
		cout << endl;
		if (enter == 1)
		{
			cout << "Enter size of data : ";
			cin >> sz;
			cout << endl;
			Segsum<int>seg(sz);
			int what;
			cout << "What do you want to do on this data ?" << endl;
			cout << "1- update element" << endl;
			cout << "2- display sum of interval" << endl;
			cout << "Enter Your Choice : ";
			cin >> what;
			if (what == 1)
			{
				int start, last;
				cout << "Enter index of element :";
				cin >> start;
				cout << endl;
				cout << "Enter value :";
				cin >> last;
				cout << endl;
				seg.update_element(start, last);
				cout << "Update Compelete" << endl;
			}
			else if (what == 2)
			{
				int start, last;
				cout << "Enter start of interval :";
				cin >> start;
				cout << endl;
				cout << "Enter end of interval :";
				cin >> last;
				cout << endl;
				cout << "Sum of this interval : ";
				cout << seg.query(start, last) << endl;
			}
		}
		else if (enter == 2)
		{
			cout << "Enter size of data : ";
			cin >> sz;
			cout << endl;
			Segmin<int>seg(sz);
			int what;
			cout << "What do you want to do on this data ?" << endl;
			cout << "1- display minimum of interval" << endl;
			cout << "2- update element" << endl;
			cout << "Enter Your Choice : ";
			cin >> what;
			if (what == 1)
			{
				int start, last;
				cout << "Enter index of element :";
				cin >> start;
				cout << endl;
				cout << "Enter value :";
				cin >> last;
				cout << endl;
				seg.update_element(start, last);
				cout << "Update Compelete" << endl;
			}
			else if (what == 2)
			{
				int start, last;
				cout << "Enter start of interval :";
				cin >> start;
				cout << endl;
				cout << "Enter end of interval :";
				cin >> last;
				cout << endl;
				cout << "minimum of this interval : ";
				cout << seg.query(start, last) << endl;
			}
		}
		else
		{
			cout << "Enter size of data : ";
			cin >> sz;
			cout << endl;
			Segmax<int>seg(sz);
			int what;
			cout << "What do you want to do on this data ?" << endl;
			cout << "1- update element" << endl;
			cout << "2- display Maximum of interval" << endl;
			cout << "Enter Your Choice : ";
			cin >> what;
			if (what == 1)
			{
				int start, last;
				cout << "Enter index of element :";
				cin >> start;
				cout << endl;
				cout << "Enter value :";
				cin >> last;
				cout << endl;
				seg.update_element(start, last);
				cout << "Update Compelete" << endl;
			}
			else if (what == 2)
			{
				int start, last;
				cout << "Enter start of interval :";
				cin >> start;
				cout << endl;
				cout << "Enter end of interval :";
				cin >> last;
				cout << endl;
				cout << "Maximum of this interval : ";
				cout << seg.query(start, last) << endl;
			}
		}
	}
}



ExpertDS::~ExpertDS()
{
}
