#include <iostream>
#include <vector>
#include <string>

class Vector3
{
public:
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3(int xPos, int yPos, int zPos)
	{
		x = xPos;
		y = yPos;
		z = zPos;
		floatingMember = 33.33f;
	}
	Vector3 operator+(Vector3 second)
	{
		Vector3 result;
		result.x = x + second.x;
		result.y = y + second.y;
		result.z = z + second.z;
		return result;
	}

	Vector3 operator-(Vector3 second)
	{
		Vector3 result;
		result.x = x - second.x;
		result.y = y - second.y;
		result.z = z - second.z;
		return result;
	}

	Vector3 operator*(Vector3 second)
	{
		Vector3 result;
		result.x = x * second.x;
		result.y = y * second.y;
		result.z = z * second.z;
		return result;
	}

	Vector3 operator/(Vector3 second)
	{
		Vector3 result;
		result.x = x / second.x;
		result.y = y / second.y;
		result.z = z / second.z;
		return result;
	}

	Vector3 operator!=(Vector3 second)
	{
		Vector3 result;
		result.x = x != second.x;
		result.y = y != second.y;
		result.z = z != second.z;
		return result;
	}

	Vector3 operator<=(Vector3 second)
	{
		Vector3 result;
		result.x = x <= second.x;
		result.y = y <= second.y;
		result.z = z <= second.z;
		return result;
	}
	void print()
	{
		std::cout << "[" << x << " " << y << " " << z << "]";
	}



	//overload operatore -,*,/,;!=
	int x, y, z;
	int SumOfCoordinates()
	{
		return x + y + z;
	}
	float GetFloatingMember()
	{
		return floatingMember;
	}
	~Vector3()
	{
		std::cout << "unistio sam se" << std::endl;

	}
	friend std::ostream & operator <<(std::ostream&output, const  Vector3 &value) // overload outputa
	{
		output << "[" << value.x << ", " << value.y << ", " << value.z << "]";
		return output;
	}

	friend std::istream &operator >>(std::istream &input, Vector3 &value) // overload inputa 
	{
		bool noerror = false;
		while (!noerror)
		{
			std::cout << "enter value x: ";
			if (!(input >> value.x))
			{
				noerror = false;
			}
			else
			{
				noerror = true;
			}
			std::cout << std::endl;
			input.clear();
			input.ignore(10000, '\n');
		}

		while (!noerror) //nema potrebe deklarirat noerrore jer se oni resetiraju prilikom promjene iz x u y etc.
		{
			std::cout << "enter value y: ";
			if (!(input >> value.y))
			{
				noerror = false;
			}
			else
			{
				noerror = true;
			}
			std::cout << std::endl;
			input.clear();
			input.ignore(10000, '\n');
		}
		while (!noerror)
		{
			std::cout << "enter value z: ";
			if (!(input >> value.z))
			{
				noerror = false;
			}
			else
			{
				noerror = true;
			}
			std::cout << std::endl;
			input.clear();
			input.ignore(10000, '\n');
		}

		return input;
	}

private:
	float floatingMember;

};

void iterarate(int*arr)
{

	for (int i = 0; i < 3; i++)
	{
		std::cout << *arr << std::endl;
		arr++;
	}
	//std::cout << i << std::endl; i je izvan scopea i ne postoji više!

}
int main()
{

	int number = 10;
	int number2 = 3;
	int* ref = &number;
	int **doubleRef = &ref;

	float fnumber = 10.5f;
	float*fRef = &fnumber;
	*ref = 30;
	int& refference = number;
	refference = number2;

	int* ptr = &number;
	std::cout << *ptr << std::endl;


	ptr = &number2;

	Vector3 person = Vector3(10, 20, 50);

	std::cout << "sum of person kordinates" << person.SumOfCoordinates() << std::endl;
	std::cout << "person kordinates x " << person.x << std::endl;
	std::cout << "person y" << person.y << std::endl;
	std::cout << " person kordinates z " << person.z << std::endl;
	std::cout << "Person s floatingMember value is :" << person.GetFloatingMember() << std::endl;



	void*personPtr = &person;
	std::cout << ref << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ref << std::endl;

	int arr[] = { 1,7,3 };
	iterarate(arr);
	std::cout << "double reference" << std::endl;
	std::cout << "doubble reference adress " << doubleRef << std::endl;
	std::cout << "double reference value " << *doubleRef << std::endl;
	std::cout << "Reference adress " << ref << std::endl;
	std::cout << "reference value " << *ref << std::endl;
	std::cout << "double reference value: " << **doubleRef << std::endl;


	{
		Vector3 position = Vector3(1, 2, 3);
	}

	Vector3 playerPosition = Vector3(35, 28, 16);
	Vector3 playerTwoPosition = Vector3(100, 100, 100);

	Vector3  sum = playerPosition + playerTwoPosition;
	Vector3 odd = playerPosition - playerTwoPosition;
	Vector3 mul = playerPosition * playerTwoPosition;
	Vector3 div = playerPosition * playerTwoPosition;



	std::cout << "vrijednost sum vectora je :";
	sum.print();
	std::cout << std::endl;

	std::cout << "vrijednost odd vectora je :";
	odd.print();
	std::cout << std::endl;

	std::cout << "vrijednost mul vectora je :";
	mul.print();
	std::cout << std::endl;

	std::cout << "vrijednost div vectora je :";
	div.print();
	std::cout << std::endl;


	std::cout << "position vector je van scopea" << std::endl;
	std::cin >> sum;
	std::cout << sum << std::endl;

	std::cin.get();

}