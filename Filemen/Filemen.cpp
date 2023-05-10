#define _CRT_SECURE_NO_WARNINGS 

#include "iostream" 

#include "Windows.h" 

#include "io.h" 

#include "direct.h" 

using namespace std;

void show_dir_in_dir() {

	cout << "Введите адрес дериктории: ";

	char dir_name[100];

	cin.getline(dir_name, 100);

	char type[] = "*.*";

	char* full_name = new char[strlen(dir_name) + strlen(type) + 2];

	strcpy(full_name, dir_name);

	strcat(full_name, "\\"); 

		strcat(full_name, type);

	cout << full_name << endl;

	_finddata_t * f = new _finddata_t;

	int desc = _findfirst(full_name, f);

	int d = desc;

	while (d != -1) {

		if (strcmp(f->name, ".") == 0 || strcmp(f->name, "..") == 0) {

			d = _findnext(desc, f);

			continue;

		}

		if (f->attrib == _A_SUBDIR) {

			cout << "Directory\t" << f->name << endl;

		}

		d = _findnext(desc, f);

	}

	_findclose(desc);

}

void show_file_in_dir() {

	cout << "Введите адресс дериктории : ";

	char dir_name[100];

	cin.getline(dir_name, 100);

	char type[] = "*.*";

	char* full_name = new char[strlen(dir_name) + strlen(type) + 2];

	strcpy(full_name, dir_name);

	strcat(full_name, "\\"); 

		strcat(full_name, type);

	cout << full_name << endl;

	_finddata_t * f = new _finddata_t;

	int desc = _findfirst(full_name, f);

	int d = desc;

	while (d != -1) {

		if (strcmp(f->name, ".") == 0 || strcmp(f->name, "..") == 0) {

			d = _findnext(desc, f);

			continue;

		}

		if (f->attrib != _A_SUBDIR) {

			cout << "File\t" << f->name << endl;

		}

		d = _findnext(desc, f);

	}

	_findclose(desc);

}

void make_dir() {

	cout << "Введите адрес где вы хотите создать новую папку : ";

	char* dir_adres = new char[100];

	cin.getline(dir_adres, 100);

	cout << "Введите название папки которую хотите создать: ";

	char* dir_name = new char[100];

	cin.getline(dir_name, 100);

	strcat(dir_adres, "\\"); 

		strcat(dir_adres, dir_name);

	_mkdir(dir_adres);

	if (_mkdir(dir_adres) == 0)

		cout << "Каталог  : " << dir_adres << ",  был создан " << endl;

	else

		cout << "При создании каталога по адресу : " << dir_adres << " возникла оибка" << endl;

}

void rem_dir(char* dir_name) {

	char type[] = "*.*";

	char* full_name = new char[strlen(dir_name) + strlen(type) + 2];

	strcpy(full_name, dir_name);

	strcat(full_name, "\\"); 

		strcat(full_name, type);

	_finddata_t * f = new _finddata_t;

	int desc = _findfirst(full_name, f);

	int d = desc;

	while (d != -1) {

		if (strcmp(f->name, ".") == 0 || strcmp(f->name, "..") == 0) {

			d = _findnext(desc, f);

			continue;

		}

		char* dir = new char[strlen(dir_name) + strlen(f->name) + 2];

		strcpy(dir, dir_name);

		strcat(dir, "\\"); 

			strcat(dir, f->name);

		if (f->attrib == _A_SUBDIR) {

			rem_dir(dir);

			_rmdir(dir);

		}

		if (f->attrib != _A_SUBDIR) {

			remove(dir);

		}

		d = _findnext(desc, f);

	}

	_findclose(desc);

}

void del_dir() {

	cout << "Введите адрес где находится папка который вы хотите удалить ";

	char* dir_adres = new char[100];

	cin.getline(dir_adres, 100);

	cout << "Введите имя папки : ";

	char* dir_name = new char[100];

	cin.getline(dir_name, 100);

	strcat(dir_adres, "\\"); 

		strcat(dir_adres, dir_name);

	cout << "Удаляемый каталог : " << dir_name << endl;

	rem_dir(dir_adres);

	_rmdir(dir_adres);

	if (_rmdir(dir_adres) == 0)

		cout << "Каталог по адресу  : " << dir_adres << ", был успешно удален" << endl;

	else

		cout << "При удалении каталога " << dir_adres << " возникла ошибка" << endl;

}

void crt_file() {

	cout << "Введите адрес папки в которой хотите создать файл : ";

	char* dir_name = new char[100];

	cin.getline(dir_name, 100);

	cout << "Введите имя файла и его расширение : ";

	char* file_name = new char[100];

	cin.getline(file_name, 100);

	strcat(dir_name, "\\"); 

		strcat(dir_name, file_name);

	cout << "Файл в процессе создания " << dir_name << endl;

	FILE * f = fopen(dir_name, "w");

	if (f == NULL)

		cout << "При создании файла по адресу: " << dir_name << " ошибка" << endl;

	else

		cout << "Файл по адресу: " << dir_name << ", был успешно создан" << endl;

	fclose(f);

}

void del_file() {

	cout << "Введите адрес папки в которой хотите создать файл : ";

	char* dir_name = new char[100];

	cin.getline(dir_name, 100);

	cout << "Введите имя файла и его расширение: ";

	char* file_name = new char[100];

	cin.getline(file_name, 100);

	strcat(dir_name, "\\"); 

		strcat(dir_name, file_name);

	cout << "Файл в процессе удаления: " << dir_name << endl;

	remove(dir_name);

	if (remove(dir_name) == NULL)

		cout << "Файл по адресу : " << dir_name << " удален" << endl;

	else

		cout << "При открытии  : " << dir_name << " ошибка" << endl;

}

void new_name_file() {

	cout << "Адрес файла  ";

	char* old_name = new char[100];

	char* adres = new char[100];

	cin.getline(adres, 100);

	strcpy(old_name, adres);

	cout << "Как назывался файл? ";

	char* name = new char[100];

	cin.getline(name, 100);

	strcat(old_name, "\\"); 

		strcat(old_name, name);

	cout << "Как назвать фал? ";

	char* new_name = new char[100];

	cin.getline(new_name, 100);

	strcat(adres, "\\"); 

		strcat(adres, new_name);

	cout << "Файл по адресу  : " << old_name << ", переименовывается в " << adres << endl;

	rename(old_name, adres);

	if (rename(old_name, adres) == NULL)

		cout << "Файл по адресу  " << old_name << ", переименован " << adres << endl;

	else

		cout << "При перемещении возникла  " << old_name << " ошибка" << endl;

}

int move_file() {

	cout << "Адрес файла: ";

	char* adres = new char[100];

	cin.getline(adres, 100);

	cout << "Ваше имя для файла: ";

	char* name = new char[100];

	cin.getline(name, 100);

	strcat(adres, "\\"); 

		strcat(adres, name);

	cout << "Введите адрес куда вы хотите переместить файл : ";

	char* new_adres = new char[100];

	cin.getline(new_adres, 100);

	strcat(new_adres, "\\"); 

		strcat(new_adres, name);

	FILE * old_f = fopen(adres, "r");

	if (old_f == NULL) {

		cout << "При перемещении файла по адресу " << adres << " лшибка" << endl;

		return 0;

	}

	FILE* new_f = fopen(new_adres, "w");

	if (new_f == NULL) {

		cout << "При перемещении файла по адресу" << adres << " ошибка" << endl;

		return 0;

	}

	char* txt = new char[100];

	while (!feof(old_f)) {

		fgets(txt, 100, old_f);

		fputs(txt, new_f);

	}

	_fcloseall();

	cout << "Файл по адресу : " << adres << ", был успещно перемещен " << new_adres << endl;

	remove(adres);

	return 0;

}

int show_file_cont() {

	cout << "Введите адрес где находится файл : ";

	char* adres = new char[100];

	cin.getline(adres, 100);

	cout << "Введите имя файла  ";

	char* name = new char[100];

	cin.getline(name, 100);

	strcat(adres, "\\"); 

		strcat(adres, name);

	FILE * f = fopen(adres, "r");

	if (f == NULL) {

		cout << "При открытии файла по адресу " << adres << " возникла ошибка" << endl;

		return 0;

	}

	char* txt = new char[100];

	fgets(txt, 100, f);

	while (!feof(f)) {

		cout << txt;

		fgets(txt, 100, f);

	}

	fclose(f);

	return 0;

}

void show_var() {

	cout << "1. Вывести на экран все каталоги на этом кустройстве " << endl;

	cout << "2. Показать все файлы в этом каталоге " << endl;

	cout << "3. Новый каталог " << endl;

	cout << "4. Удалить существующий каталог" << endl;

	cout << "5. Создать новый файл в данном каталоге" << endl;

	cout << "6. Удалить существующий файл" << endl;

	cout << "7. Переименовать указанный файл" << endl;

	cout << "8. Переместить файл в указанный пользователем каталог" << endl;

	cout << "9. Вывести содержание файла на экран" << endl;

}

int main() {

	SetConsoleOutputCP(1251);

	SetConsoleCP(1251);

	int s;

	do {

		show_var();

		cout << "Выберите какое действие хотите провести : ";

		int var;

		cin >> var;

		cin.ignore();

		system("CLS");

		switch (var) {

		case 1: show_dir_in_dir();

			break;

		case 2: show_file_in_dir();

			break;

		case 3: make_dir();

			break;

		case 4: del_dir();

			break;

		case 5: crt_file();

			break;

		case 6: del_file();

			break;

		case 7: new_name_file();

			break;

		case 8: move_file();

			break;

		case 9: show_file_cont();

			break;

		}

		system("pause");

		system("CLS");

		cout << "Желаете ли вы провести еще действия?\t1.да 2.Нет" << endl;

		cin >> s;

		cin.ignore();

		system("CLS");

	} while (s == 1);

	return 0;

}