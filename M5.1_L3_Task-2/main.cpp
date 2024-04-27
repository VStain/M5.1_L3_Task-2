// Задача 2. Копирование умных массивов

/*
Описание
В этом задании вам нужно поработать с классом умных массивов, который вы реализовали в предыдущем задании. 
Сначала попробуйте создать два экземпляра вашего класса с различными элементами и присвоить один другому.

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
	int* data = 0;     // Указатель на массив данных
	int size = 0;      // Размер массива 
	int capacity = 0;  // Вместимость массива

	// Фун-я для выделения памяти
	void allocate_memory()
	{
		data = new int[capacity];
		if (!data)
		{
			throw std::bad_alloc();
		}
	}

	// Фун-я освобождения памяти
	void deallocate_memory()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}
public:
	// Конструктор
	explicit smart_array(int initial_size) : size(0), capacity(initial_size)
	{
		allocate_memory();
	}

	// Деструктор
	~smart_array()
	{
		deallocate_memory();
	}

	// Конструктор копирования =
	smart_array(const smart_array& other) {
		size = other.size;
		capacity = other.capacity;
		data = new int[capacity];
		for (int i = 0;i < size; ++i) {
			data[i] = other.data[i];
		}
	}


	// Фун-я добавления элемента
	void add_element(int element)
	{
		if (size == capacity)
		{
			// Увеличиваем вместимость массива, если он заполнен
			int new_capacity = capacity * 2;
			int* new_data = new int[new_capacity];


			// Копируем данные в новый массив
			for (int i = 0; i < size; ++i) {
				new_data[i] = data[i];
			}

			// Освобождаем память старого массива
			deallocate_memory();

			// Обновляем данные
			data = new_data;
			capacity = new_capacity;
		}

		data[size] = element;
		size++;
	}

	// Фун-я получения элемента по индексу
	int get_element(int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Индекс выходит за пределы массива");
		}

		return data[index];
	}

	// Функция для вывода массива
	void print_array() const {
		for (int i = 0; i < size; ++i) {
			std::cout << data[i] << ", ";
		}
		std::cout << std::endl;
	}

	
};

int main() {

	setlocale(LC_ALL, "ru");

	try {
		/*smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.print_array();

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		

		arr = new_array;
		*/
		smart_array arr1(5);
		arr1.add_element(1);
		arr1.add_element(2);
		arr1.add_element(3);


		smart_array arr2(arr1);

		arr1.print_array();
		arr2.print_array();

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}