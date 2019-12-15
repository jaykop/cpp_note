class myString
{
	
public:
	
	myString(char c);
	myString(const char* str);
	myString(const myString& str;)
	
	~myString();
	
	void assign();
	char * at(int i);
	void compare(const std);
	int length();
	
private:
	
	char* content_;
	int len_;
};