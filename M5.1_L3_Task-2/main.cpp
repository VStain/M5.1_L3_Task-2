// ������ 2. ����������� ����� ��������

/*
��������
� ���� ������� ��� ����� ���������� � ������� ����� ��������, ������� �� ����������� � ���������� �������. 
������� ���������� ������� ��� ���������� ������ ������ � ���������� ���������� � ��������� ���� �������.

smart_array arr(5);
arr.add_element(1);
arr.add_element(4);
arr.add_element(155);

smart_array new_array(2);
new_array.add_element(44);
new_array.add_element(34);

arr = new_array
*/

#include <iostream>
#include <stdexcept>

class smart_array
{
private:
	int* data = 0;     // ��������� �� ������ ������
	int size = 0;      // ������ ������� 
	int capacity = 0;  // ����������� �������

	// ���-� ��� ��������� ������
	void allocate_memory()
	{
		data = new int[capacity];
		if (!data)
		{
			throw std::bad_alloc();
		}
	}

	// ���-� ������������ ������
	void deallocate_memory()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}
public:
	// �����������
	explicit smart_array(int initial_size) : size(0), capacity(initial_size)
	{
		allocate_memory();
	}

	// ����������
	~smart_array()
	{
		deallocate_memory();
	}

	// ���-� ���������� ��������
	void add_element(int element)
	{
		if (size == capacity)
		{
			// ����������� ����������� �������, ���� �� ��������
			int new_capacity = capacity * 2;
			int* new_data = new int[new_capacity];


			// �������� ������ � ����� ������
			for (int i = 0; i < size; ++i) {
				new_data[i] = data[i];
			}

			// ����������� ������ ������� �������
			deallocate_memory();

			// ��������� ������
			data = new_data;
			capacity = new_capacity;
		}

		data[size] = element;
		size++;
	}

	// ���-� ��������� �������� �� �������
	int get_element(int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("������ ������� �� ������� �������");
		}

		return data[index];
	}

	// ������� ��� ������ �������
	void print_array() const {
		for (int i = 0; i < size; ++i) {
			std::cout << data[i] << ", ";
		}
		std::cout << std::endl;
	}

	// �������� ������������ =
	smart_array& operator=(const smart_array& other) {
		if (this != &other) {
			// ����������� ������, �� ������� ��������� this
			deallocate_memory();

			// �������� �������� �������
			size = other.size;
			capacity = other.capacity;
			data = new int[capacity];
			for (int i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}

		}
		return *this;
	}
};

int main() {

	setlocale(LC_ALL, "ru");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.print_array();

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		

		arr = new_array;

		arr.print_array();

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}