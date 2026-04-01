#include <iostream>
#include <vector>
#include <fstream>



using namespace std;







class Student
{
public:

    string name;
    string lastname;
    vector<int> nota;
    int id;
    double ponderation;

    Student(string n, string lastname, int i, double p ){
        name = n;
        this->lastname = lastname;
        id = i;
        ponderation = p;
    }
    void addNote(int note) {
        nota.push_back(note);
    }
    
        
};

vector<Student> listStudents;

//Funciones
bool foundStudent(int ci);
void addStudent(Student s);
void modifyStudent(int ci);
int readStudent(int ci);
void readFile();
void reWriteFile();
void createStudent();
void mostrarEstudiantes();





int main(){
    bool runing = true;
    int opcion;
    int ci;
    readFile();
    do
    {
        cout<<"########### Bienvenido a mi programa de administracion de estudiantes ##############\n";
        cout<<"Que desea hacer:\n";
        cout<<"1. Agregar un estudiante\n";
        cout<<"2. Verificar los datos de un estudiante\n";
        cout<<"3. Modificar los datos de un estudiantes\n";
        cout<<"4. Mostrar todos los estudiantes\n";
        cout<<"0. Salir del programa\n";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            createStudent();
            break;
        case 2:
            
            cout<<"Por favor ingrese la cedula del estudiante que desea verificar\n";
            cin>>ci;
            readStudent(ci);
            break;
        case 3:
            
            cout<<"Por favor ingrese la cedula del estudiante que desea modificar\n";
            cin>>ci;
            modifyStudent(ci);
            break;
        case 4:
            mostrarEstudiantes();
            break;
        case 0:
            cout<<"saliendo....\n";
            runing = false;
            break;
        
        default:
            cout<<"Lo siento opcion no valida pruebe de nuevo";
            break;
        }

        

    } while (runing);
    
    

    
    reWriteFile();

} 

void addStudent(Student s){
    
    if (foundStudent(s.id))
    {   
        char opcion;
        cout<<"el estudiante ya existe\n";
        cout<<"Desea modificarlo? y/n\n";
        cin>>opcion;
        if (opcion == 'y')
        {
            modifyStudent(s.id);
        }
      
    }else{
    listStudents.push_back(s);
    
}}

int readStudent(int ci){
    
    
        
    if (foundStudent(ci)){

    for (long long unsigned int i = 0; i < listStudents.size(); i++)
    {
        if (ci == listStudents[i].id)
        {
            cout<<"El estudiante de cedula: "<<ci<<" fue encontrado....\n";
            cout<<"Sus datos son: "<<endl;
            cout<<"Nombre: "<<listStudents[i].name<<endl;
            cout<<"Apellido: "<<listStudents[i].lastname<<endl;
            cout<<"cedula: "<<listStudents[i].id<<endl;
            cout<<"Promedio: "<<listStudents[i].ponderation<<endl;
            
            return 0;
        }
        
    }
    }else{
        cout<<"El estudiante no fue encontrado";
        return -1;
    }
    
}
        
    

bool foundStudent(int ci){

    for (long long unsigned int i = 0; i < listStudents.size(); i++)
    {
        if (ci == listStudents[i].id)
        {
            cout<<"El estudiante  existe\n";
            return true;
        }
        
    }
    
    return false;
    
}

void modifyStudent(int ci){
    
    if(foundStudent(ci)){
        
        for (long long unsigned int i = 0; i < listStudents.size(); i++)
    {
        if (ci == listStudents[i].id)
        {   
            int opcion;
            double newPon;
            string NewDate;
            cout<<"Que dato desea cambiar\n";
            cout<<"1. Para cambiar el nombre\n";
            cout<<"2. Para cambiar el apellido\n";
            cout<<"3. Para cambiar el promedio\n";
            cout<<"4. Para cancelar\n";
            cin>>opcion;
            switch (opcion)
            {
            case 1:
                cout<<"Ingrese el nuevo nombre";
                cin>>NewDate;
                listStudents[i].name = NewDate;
                break;
            case 2:
                cout<<"Ingrese el nuevo apellido";
                cin>>NewDate;
                listStudents[i].lastname = NewDate;
                break;
            case 3:
                cout<<"Ingrese el nuevo promedio";
                cin>>newPon;
                listStudents[i].ponderation = newPon;
                break;
            case 4:
            cout<<"cancelando....";
                break;
            
            default:
                cout<<"esa opcion no esta disponible";
                break;
            }
            
        }
        
    }

        
        

    }else{
        cout<<"Lo siento pero no se ha encontrado al estudiante";
        
    }
};

void readFile(){
    fstream file;
    file.open("prueba.txt",ios::in);
    int id;
    string name,lastname;
    double ponderation;
    while (file >> name >> lastname >> id >> ponderation)
    {
        Student readStudents = Student(name, lastname, id,ponderation);
        listStudents.push_back(readStudents);
        

    }
    file.close();
    
}
void reWriteFile(){

    ofstream file("prueba.txt");
    for (long long unsigned int i = 0; i < listStudents.size(); i++)
    {
        file<<listStudents[i].name<<" "<<listStudents[i].lastname<<" "<<listStudents[i].id<<" "<<listStudents[i].ponderation<<endl;
    }
    file.close();
    
}
void createStudent(){
    int id;
    string name,lastname;
    double ponderation;

    cout<<"Agrege el nombre y apellido del estudiante todo en minusculas: ";
    cin>>name>>lastname;
    cout<<"agrege el numero de cedula del estudiante: ";
    cin>>id;
    cout<<"agrege el promedio del estudiante";
    cin>>ponderation;

    Student newStudent = Student(name,lastname,id,ponderation);
    addStudent(newStudent);

};

void mostrarEstudiantes(){
    for (long long unsigned int i = 0; i < listStudents.size(); i++)
    {
        cout<<"Nombre: "<<listStudents[i].name<<endl;
        cout<<"Apellido: "<<listStudents[i].lastname<<endl;
        cout<<"cedula: "<<listStudents[i].id<<endl;
        cout<<"Promedio: "<<listStudents[i].ponderation<<endl;
    }
    
}