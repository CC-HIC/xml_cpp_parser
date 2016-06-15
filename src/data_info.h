#ifndef CCXML_DATA_INFO_H
#define CCXML_DATA_INFO_H

#include "type.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

class DataInfo {
  public:
    std::string filename;
    std::map<std::string, t_vstring> nhic_code_list;
    //!  using NHIC code as keys and 
    std::map<std::string, code_type> nhic_code_category;
    std::map<std::string, std::string> item2time;
    std::map<std::string, std::string> item2meta;
    t_vstring check_list = {"NHICcode", "NHICdtCode", "NHICmetaCode"};

    void GetCodeList(std::map<std::string, t_vstring>& code_list);
    void GetCategoryList(std::map<std::string, code_type>& category);
    void GetSearchTable();
    
    DataInfo(){};
    //! constructor update data information from a give csv file.
    DataInfo(std::string file_name): filename(file_name){
      GetCodeList(nhic_code_list);
      GetCategoryList(nhic_code_category);
      GetSearchTable();
    };

  private:
    t_vstring ReadOneLine(std::ifstream &file);
};
#endif
