let model
let previousPen="down"
let x,y
//가장 중요한 변수
let strokePath
let seedStrokes=[]

let canvas

function  preload() {
    model=ml5.sketchRNN("dog",modelReady)
}

function modelReady(){
    console.log('model is ready.')
}

function setup() {
    canvas=createCanvas(600,400)
    canvas.mousePressed(resetDrawing)
    canvas.mouseReleased(startSketchRNN)

    background(234)//회색

    model.generate(seedStrokes, gotStroke)
}

function gotStroke(err, result) {
    strokePath=result    
}

function resetDrawing(){//초기화 함수
    seedStrokes=[]
    model.reset()
}

function startSketchRNN() {
    x=mouseX
    y=mouseY//마지막 마우스 위치에서 그리기 시작하여라
    model.generate(seedStrokes,gotStroke)
}

function draw(){
    if(mouseIsPressed){
        stroke(0,225,0)
        strokeWeight(6)
        line(pmouseX,pmouseY,mouseX,mouseY)

        const userStroke={
            dx:mouseX-pmouseX,
            dy:mouseY-pmouseY,
            pen:"down"
        }
        seedStrokes.push(userStroke)

        
    }
    if(strokePath){
        if(previousPen=="down"){
            stroke(0)//검은색
            strokeWeight(6)
            line(x,y,x+strokePath.dx, y+strokePath.dy)
        }
        x+=strokePath.dx
        y+=strokePath.dy
        previousPen=strokePath.pen

        if(strokePath.pen!=="end"){
            strokePath=null
            model.generate(gotStroke)
        }
    }
    
}