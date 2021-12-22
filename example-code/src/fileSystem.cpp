#include "fileSystem.h"

JsonValue fileIO(JsonView parameters)
{
  Aws::SimpleStringStream ss;
  string data,fileName,mode;
  if (parameters.ValueExists("data")) data = parameters.GetString("data");
  if (parameters.ValueExists("fileName")) fileName = parameters.GetString("fileName");
  if (parameters.ValueExists("mode")) mode = parameters.GetString("mode");
  // extract the data will be written to the file, the file name and the mode (wirte/read) from the parameters
  
  JsonValue output;
  if (mode == "read")
    {
      /* read file */
      ifstream readfile(FILEPATH+fileName);
      string text;
      while (getline(readfile,text)) ss<<text;
      readfile.close();
      output.WithString("message", "successfully read data from the file "+ fileName);
      output.WithString("content", ss.str());
    }
  else
    {
      /* write file */
      ofstream outfile(FILEPATH+fileName);
      outfile<<data;
      outfile.close();
      output.WithString("message", data + " is wrriten to the file " + fileName);
    }
  return output;
}
