#include "funciones.h"

bool son_iguales(const string a, const string b){
    if(a.length() != b.length())
        return false;
    
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i])
            if(a[i] != b[i] + 32)
                if(a[i] != b[i] - 32)
                    return false;
    }
    
    return true;
}