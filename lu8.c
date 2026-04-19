#include <stdio.h>
#include <math.h>

//1
struct Point{
    float x, y, z;
};
typedef struct Point Point;

float distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

//2
struct Vehicle{
    char brand[20];
    int max_speed;
    int weight;
};
typedef struct Vehicle Vehicle;

struct Car{
    Vehicle v;
    char fuel[10];
    int doors;
};
typedef struct Car Car;

//3
struct Student{
    char name[30];
    float grade;
};
typedef struct Student Student;

struct Class{
    Student students[30];
    int students_count;
};
typedef struct Class Class;

struct Graduation{
    Class classes[5];
    int classes_count;
};
typedef struct Graduation Graduation;

float avg_class(Class cl){
    float sum = 0;
    for(int i = 0; i < cl.students_count; i++)
    {
        sum += cl.students[i].grade;
    }
    return sum / cl.students_count;
}

float avg_graduation(Graduation grad){
    float sum = 0;
    int total_students = 0;
    for(int i = 0; i < grad.classes_count; i++)
    {
        for(int j = 0; j < grad.classes[i].students_count; j++)
        {
            sum += grad.classes[i].students[j].grade;
            total_students++;
        }
    }
    return sum / total_students;
}

//4
struct Book{
    char title[50];
    char author[50];
    int year;
    float price;
};
typedef struct Book Book;

void books_info(Book b[], int n){
    int max_index = 0, min_index = 0;
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += b[i].price;
        if(b[i].price > b[max_index].price) max_index = i;
        if(b[i].price < b[min_index].price) min_index = i;
    }

    printf("\nNai-evtina kniga: %s (%.2flv)\n", b[min_index].title, b[min_index].price);
    printf("\nNai-skupa kniga: %s (%.2flv)\n", b[max_index].title, b[max_index].price);
    printf("\nSredna cena: %.2flv\n", sum / n);
}

int main() {
    //1
    /*Point points[6];
    for(int i = 0; i < 3; i++)
    {
        printf("Vuvedete koordinatite(x,y,z) na tochka %d:", i+1);
        scanf("%f%f%f", &points[i].x, &points[i].y, &points[i].z);
    }

    float AB = distance(points[0], points[1]);
    float BC = distance(points[1], points[2]);
    float AC = distance(points[2], points[0]);
    if (AB + BC > AC && AB + AC > BC && AC + BC > AB)
    {
        printf("\nStranite na triugulnika ABC sa:\n");
        printf("AB = %.2f\n", AB);
        printf("BC = %.2f\n", BC);
        printf("CA = %.2f\n", AC);
    }
    else printf("Ne sushtestvuva triugulnik s takiva strani.");*/

    //2
    /*Car car = {{"BMW", 240, 1500}, "Diesel", 4};
    Vehicle motor = {"Yamaha", 180, 200};
    Vehicle boat = {"Bayliner", 90, 1200};
    Vehicle plane = {"Boeing", 850, 40000};

    Vehicle fastest = car.v;
    if (motor.max_speed > fastest.max_speed) fastest = motor;
    if (boat.max_speed > fastest.max_speed) fastest = boat;
    if (plane.max_speed > fastest.max_speed) fastest = plane;

    printf("Nai burzoto prevozno sredstvo ot izbroenite e: %s (%dkm/h)", fastest.brand, fastest.max_speed);*/

    //3
    /*Graduation grad;
    printf("Broi klasove:");
    scanf("%d", &grad.classes_count);

    for(int i = 0; i < grad.classes_count; i++)
    {
        printf("Broi uchenici v klas %d:", i+1);
        scanf("%d", &grad.classes[i].students_count);
        for(int j = 0; j < grad.classes[i].students_count; j++)
        {
            printf("Ime i uspeh na uchenik nomer %d:", j + 1);
            scanf("%s %f", grad.classes[i].students[j].name, &grad.classes[i].students[j].grade);
        }
    }

    for(int i = 0; i < grad.classes_count; i++)
    {
        printf("Sredniqt uspeh na klas %d e %.2f.\n", i+1, avg_class(grad.classes[i]));
    }

    printf("Sredniqt uspeh na vipuska e %.2f.\n", avg_graduation(grad));*/

    //4
    Book books[5];
    for(int i = 0; i < 5; i++)
    {
        printf("Kniga %d\n", i + 1);

        printf("Zaglavie: ");
        fgets(books[i].title, 50, stdin);

        printf("Avtor: ");
        fgets(books[i].author, 50, stdin);

        printf("Godina: ");
        scanf("%d", &books[i].year);

        printf("Cena: ");
        scanf("%f", &books[i].price);

        getchar();

        printf("----------\n");
    }

    books_info(books, 5);

    return 0;
}
