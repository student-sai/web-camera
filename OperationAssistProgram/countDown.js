      var min = 0;
      var sec = 0;
      var millisec = 0;
      var cnt = 0;
      var min_lim = 1; //制限時間をセット
      
      function countDown(){
        document.getElementById("CountDownArea").innerHTML =
        //.slice(-2)で左から2桁だけ取り出す
        ("0"+min).slice(-2)+":" +
        ("0"+sec).slice(-2)+":" +
        ("0"+millisec).slice(-2);
         
        millisec = 100 - cnt%100;
        sec = Math.floor(60 - cnt/100%60);
        min = Math.floor(min_lim - cnt/100/60%60);
        
        cnt++;
        if (min < 0 ){
          document.getElementById("CountDownArea").innerHTML = 
              min_lim + ":00:00";
          alert("時間切れです。");
          cnt = 0;
        }
      }
      setInterval("countDown()", 10);