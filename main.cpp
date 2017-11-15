#include "csv.h"
#include "iostream"
#include <boost/filesystem.hpp>


bool has_suffix(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main(){

//  boost::filesystem::path path = boost::filesystem::current_path();
  boost::filesystem::path path("/Users/rsmith/Documents/Github/fast-cpp-csv-parser/test_csvs/");
  boost::filesystem::recursive_directory_iterator itr(path);
  while (itr != boost::filesystem::recursive_directory_iterator())
    {

      std::string path_to_file = itr->path().string();
      std::cout << itr->path().string() << std::endl;
      ++itr;

      if( has_suffix(path_to_file, ".csv")){

	  io::CSVReader<3> in(path_to_file);
	  in.read_header(io::ignore_extra_column, "vendor", "size", "speed");
	  std::string vendor; int size; double speed;
	  while(in.read_row(vendor, size, speed)){
	    std::cout << vendor << size << speed << std::endl;
	    // do stuff with the data
	  }
	}
   }
}
