function doGet(e){
  var mo = e.parameter.func;
  if(mo == "addData"){
    var stat = add_data(e);
    if(stat == 1){
      var result = {
        status: true
      };
    return ContentService.createTextOutput(JSON.stringify(result))
    .setMimeType(ContentService.MimeType.JSON);
    }
  }
}

function add_data(e){
  var sheet = SpreadsheetApp.openByUrl('https://docs.google.com/spreadsheets/d/1seaExPn_y0497gKqZRDY5HHm_04eQP9bARWmV8ZwM9Q/edit#gid=0');
  
  var lastVal = sheet.getRange("A1:A").getValues();
  var id = lastVal.filter(String).length;
  
  var CurrentDate = new Date() ;  
  var Date_ = Utilities.formatDate(CurrentDate, "IST", "dd/MM/yyyy") ;
  var Time_ = Utilities.formatDate(CurrentDate, "IST", "HH:mm:ss") ;
 
  sheet.appendRow([id,Date_,Time_,e.parameter.val]);  


  return 1;
}