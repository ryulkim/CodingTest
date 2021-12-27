/*
const say = {
    hel1 : function hello(data0){
        let time = null;
        let time1 = ['h','e','l','l','o'];
        const data = {
        data1 : "1",
        data2 : "2",
        data3 : "3",
        }

        data.data4 = "4"

        //console.log(data0);
        //alert(typeof data0);
        return parseInt(data0);
    }
}


const age = prompt("이름을 입력하여라");
const result = say.hel1(age); 

*/
const title = document.querySelector(".hi:first-child h1");

title.innerText = "t eacher";

//title.style.color = "blue"
//title.className = "good job"

//console.dir(title);
//console.log(title);

var a = 0;

title.addEventListener("mouseenter", myevent);
title.addEventListener("mouseleave", myevent2);
title.addEventListener("click", myevent3)
//title.onclick = myevent3;

window.addEventListener("resize", myevent4);
window.addEventListener("online", myevent5)
window.addEventListener("offline", myevent5)
window.onoffline = myevent5;

function myevent()
{
    //title.className = "active"
    if(a == 0){
        console.log(title);
        //title.style.color = "blue"
    }
}

function myevent2()
{
    //title.className = "active"
    if(a == 0){
        //title.style.color = "black"
    }
}

function myevent3()
{
    //title.className = "active"

    const click_ed = "active"


    title.classList.toggle(click_ed)
    //title.style.color = "red" 
    a = !a    
}

function myevent4()
{
    document.body.style.backgroundColor = "green"
}

function myevent5()
{
    document.body.style.backgroundColor = "blue"
}


console.log(a);
console.dir(title);

/*
if(isNaN(result)) alert(false);

else if(result === 16)
{
    alert(true);
}

else alert(false);
*/

//say.hello("world");
