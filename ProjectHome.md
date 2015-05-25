Yujia,Yue,Jiacheng,Baifeng

vector

&lt;Task&gt;

 VeriTask::searchTask(string keyword) {
> vector

&lt;Task&gt;

 taskListFound;

> for (vector

&lt;Task&gt;

::iterator i=_taskList.begin(); i<_taskList.end(); i++) {

> string tempEvent = (**i).getEvent();
> string tempDate = (**i).getDate();
> string tempStartTime = (**i).getStartTime();
> string tempEndTime = (**i).getEndTime();
> if ((tempEvent.find(keyword)!=string::npos)
> > (tempDate.find(keyword)!=string::npos) 
> > (tempStartTime.find(keyword)!=string::npos) 
> > (tempEndTime.find(keyword)!=string::npos)) {
> > taskListFound.push\_back((**i));**


> }
> }
> return taskListFound;
}