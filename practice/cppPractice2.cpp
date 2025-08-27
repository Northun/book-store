// Zigzag Conversion


  string convert(string s, int numRows) {
      if (numRows == 1 || numRows >= s.length()) {
          return s;
      }

      int direction = 1;
      int rowN = 0;

      vector<vector<char>> output(numRows);

      for (char c: s){
          output[rowN].push_back(c);
          if (rowN == 0){
              direction = 1;
          }
          else if(rowN == numRows-1){
              direction = -1;
          }
          rowN = rowN + direction;
      }

      string result;
      for (const auto& row:output){
          for (char c:row){
              result = result + c;
          }
      }

      return result;
  }

