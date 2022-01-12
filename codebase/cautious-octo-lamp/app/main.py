from fastapi import FastAPI, Request, Form
from fastapi.templating import Jinja2Templates
import subprocess
#venv\Scripts\uvicorn main:app --app-dir cautious-octo-lamp\app\ --reload

app = FastAPI()
templates = Jinja2Templates(directory="cautious-octo-lamp/templates/")


@app.get("/")
def zipcode_post(request: Request):
    #result = "Type your zipcode"
    return templates.TemplateResponse('index.html', context={'request': request})

@app.post("/")
def zipcode_post(request: Request, zipcode: str = Form(...)):
    subprocess_output = subprocess.run(['java', '-jar', 'placeholder_runnable.jar'], input=zipcode.encode('utf-8'), capture_output=True)
    result = str(subprocess_output.stdout)
    result = result.removeprefix("b'")
    result = result.removesuffix("'")
    result = result.removesuffix(r'\n')
    result = result.removesuffix(r'\r')
    resultlist = result.split(", ")
    return templates.TemplateResponse('index.html', context={'request': request, 'result1': resultlist[0], \
                                                             'result2': resultlist[1], 'result3': resultlist[2], \
                                                             'result4': resultlist[3]})

@app.get("/Cabbage")
def cabbage(request: Request):
    return templates.TemplateResponse('Cabbage.html', context={'request': request})