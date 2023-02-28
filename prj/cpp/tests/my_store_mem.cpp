#include "my_store_mem.h"



#include <QtDebug>
#include <QString>


//-------------------------------------------------------
bool MyStoreMem::has_name(int id)
{
    return id_to_name.contains(id);
}
//-------------------------------------------------------
QString MyStoreMem::read_name(int id)
{
    return id_to_name.value(id, "not found");
}
//-------------------------------------------------------
bool MyStoreMem::write_name(int id, QString Name)
{

    id_to_name.insert(id, Name);
    return true;

}






