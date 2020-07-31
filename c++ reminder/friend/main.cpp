#include <iostream>

class Patient
{
	friend class Doctor;

protected:
	// const char* name;

private:
	int health_ = 0;

public:

	std::ostream& operator<<(std::ostream& os)
	{
		os << this->health_ << "\n";
		return os;
	}

	Patient& operator++() { ++health_; return *this; }
	Patient operator++(int) { auto result = *this; ++health_; return result; }

	friend std::ostream& operator<<(std::ostream& os, const Patient& p);
};

std::ostream& operator<<(std::ostream& os, const Patient& p)
{
	os << p.health_ << "\n";
	return os;
}

class Doctor
{
public :

	void Heal(Patient& p) { ++p.health_; };
};

int main()
{
	Patient p;
	Doctor d;

	p << std::cout;

	d.Heal(p);

	std::cout << p;

	std::cout << p++;
	std::cout << ++p;

	return 0;
}