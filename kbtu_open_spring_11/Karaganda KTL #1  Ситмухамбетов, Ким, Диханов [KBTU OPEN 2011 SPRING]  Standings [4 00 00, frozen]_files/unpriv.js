// $Id: unpriv.js 5348 2008-11-19 16:42:35Z cher $

// Copyright (C) 2008 Alexander Chernov <cher@ejudge.ru>

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

var reloadTimer = null;
var clockTimer = null;
var pingTimer = null;

//handling errors within AJAX communications
function handleError(type, errObj)
{ 
  /* FIXME: should not report error
  alert("ERROR: " + errObj.message);
  */
}

//pretty printer
function printTime()
{
  var placeToAdd = document.getElementById("currentTime");

  if(placeToAdd.childNodes.length == 1)
    placeToAdd.removeChild(placeToAdd.childNodes[0]);

  var localTime = document.createTextNode((jsonState.h < 10 ? "0" : "") + jsonState.h + ":" + (jsonState.m < 10 ? "0" : "") + jsonState.m + ":" + (jsonState.s < 10 ? "0" : "") + jsonState.s);
  placeToAdd.appendChild(localTime);

  if (jsonState.r != null) {
    placeToAdd = document.getElementById("remainingTime");
    if (placeToAdd.childNodes.length == 1)
      placeToAdd.removeChild(placeToAdd.childNodes[0]);

    var hh = jsonState.r;
    var ss = hh % 60;
    if (ss < 10) ss = "0" + ss;
    hh = (hh - ss) / 60;
    var mm = hh % 60;
    if (mm < 10) mm = "0" + mm;
    hh = (hh - mm) / 60;
    localTime = document.createTextNode(hh + ":" + mm + ":" + ss);
    placeToAdd.appendChild(localTime);
  }
}

//updates local time for 1 second
function updateLocalTime()
{
  if (jsonState.r != null) {
    jsonState.r--;
    if (jsonState.r < 0) {
      jsonState.r = null;
      document.location.href = script_name + "?SID=" + SID + "&action=" + NEW_SRV_ACTION_VIEW_PROBLEM_SUMMARY;
    }
  }

  jsonState.s++;
  if (jsonState.s >= 60) {
    jsonState.s -= 60;
    jsonState.m++;
    if (jsonState.m >= 60) {
      jsonState.m -= 60;
      jsonState.h++;
      if (jsonState.h >= 24) {
        jsonState.h -= 24;
      }
    }
  }
  printTime();
}

function reloadPage()
{
  window.location.reload();
}

function updateTime()
{
  if (reloadTimer != null) {
    clearInterval(pingTimer);
    clearInterval(reloadTimer);
    clearInterval(clockTimer);
    window.location.reload();
    return;
  }
  clearInterval(pingTimer);
  dojo.xhrGet({
      url: script_name,
      content: {
        "SID": SID,
        "action": NEW_SRV_ACTION_JSON_USER_STATE
      },
      handleAs: "json",
      error: function(data, ioargs) {
        alert("Request failed: " + data);
      },
      load: function(data, ioargs) {
        jsonState = data;
        printTime();
        pingTimer = window.setInterval(updateTime, 60000);
        if (jsonState.x != null) 
          reloadTimer = window.setInterval(reloadPage, 5000);
      }
  });
}

function startClock()
{
  clockTimer = window.setInterval(updateLocalTime, 1000);
  pingTimer = window.setInterval(updateTime, 60000);
  if (jsonState.x != null) {
    reloadTimer = window.setInterval(reloadPage, 5000);
  }
}

function submitStatus(type, data, evt)
{
}

function submitAnswer(action, probId, answer, next_action, nextProbId)
{
  dojo.xhrPost({
      url: script_name,
      content: {
        "SID": SID,
        "action": action,
        "prob_id": probId,
        "json": 1,
        "file": answer
      },
      handleAs: "json",
      error: function(data, ioargs) {
        alert("Request failed: " + data);
      },
      load: function(data, ioargs) {
        if (data.status < 0) {
          alert("Operation failed: " + data.text);
        } else {
          if (nextProbId != null) {
            document.location.href = self_url + "?SID=" + SID + "&action=" + next_action + "&prob_id=" + nextProbId;
          }
        }
      }
  });
}

function displayProblemSubmitForm(action, probId)
{
  document.location.href = script_name + "?SID=" + SID + "&action=" + action + "&prob_id=" + probId;
}

