function newImage(arg) {
  if(document.images){
	rslt = new Image()
	rslt.src = arg
	return rslt
  }
}

function LoadImages() {
  if (document.images) {
    var x
    x = newImage("images/l_lines.gif")
    x = newImage("images/r_lines.gif")
    x = newImage("images/s_lines.gif")
    x = newImage("images/v_lines.gif")
    x = newImage("images/favicon.ico")
  }
}

function ValidLF(){
  if(!enter.lgn.value){
    alert('���������� ������� �����')
    enter.lgn.focus()
  }else 
  if(!enter.password.value){
    alert('���������� ������� ������')
    enter.password.focus()
  }
  else {return true}
  return false
}

function ShowTime(){ 
  now.setTime(now.getTime()+1000)
  timer.innerHTML =now.toLocaleString()+"&nbsp;"
  window.setTimeout('ShowTime()',1000)
}

