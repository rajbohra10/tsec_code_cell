var https = require('https')
var htmlToJson = require('html-to-json')
var parseString = require('xml2js').parseString
var firebase = require('firebase')
var config = {
    apiKey: "AIzaSyDGnzlt9t4IjOnnHzlEGQ0kZOyuuFelRLs",
    authDomain: "testingproject-9a555.firebaseapp.com",
    databaseURL: "https://testingproject-9a555.firebaseio.com",
    projectId: "testingproject-9a555",
    storageBucket: "testingproject-9a555.appspot.com",
    messagingSenderId: "482299053520"
};
var oldRssGuid
var newRssGuid
var index = 0
firebase.initializeApp(config)
var database = firebase.database()
var url = "https://news.google.com/news/rss/headlines/section/topic/TECHNOLOGY.en_in/Technology?ned=in&hl=en-IN&gl=IN"
// getting data from firebase
var ref = database.ref('oldRssTechnology')
var technologyRef = database.ref('Technology')
ref.on('value', (data) => {
    oldRssGuid = Object.values(data.val())
    // console.log(oldRssGuid)
    goAhead(oldRssGuid)
}, (err) => {
    console.log(`Error! -----> ${err}`)
})

let count = 0;
// checks new RSS with old RSS
function goAhead(oldRssGuid) {
    console.log(oldRssGuid)
    xmlToJson(url, (err, data) => {
        if (err) {
            return console.log(err)
        } else {
            // console.log("The new RSS Feed guid are ---> ")
            // for (let index = 0; index < 20; index++) {
            //     let guid = JSON.stringify(JSON.stringify(data['rss']['channel'][0]['item'][index]['guid'][0]["_"].split('=')[1]))
            //     guid = guid.substring(1, guid.length - 1)
            //     guid = guid.replace(/\\/g, '');
            //     for (let index2 = 0; index2 < 20; index2++) {
            //         if (!(guid === oldRssGuid[index2])) {
            //             //    console.log(guid)
            //             //    console.log(oldRssGuid[index2])
            //             //     console.log('false')
            //             if (index2 == 19) {
            //                 let title = JSON.stringify(data['rss']['channel'][0]['item'][index]['title'][0])
            //                 console.log(title)
            //                 title = title.substring(1, title.length - 1)
            //                 let pubDate = JSON.stringify(data['rss']['channel'][0]['item'][index]['pubDate'][0])
            //                 pubDate = pubDate.substring(1, pubDate.length - 1)
            //                 let link = JSON.stringify(data['rss']['channel'][0]['item'][index]['link'][0])
            //                 link = link.substring(1, title.length - 1)
            //                 let desc = JSON.stringify(data['rss']['channel'][0]['item'][index]['description'][0])
            //                 var promise = htmlToJson.parse(desc , {
            //                     'text': function (doc) {
            //                     return doc.find('strong').text();
            //                     }
            //                 }, function (err, result) {
            //                     result = result['text'].split(/\s\s/)[1]
            //                     let obj = {}
            //                     obj['title'] = title
            //                     obj["link"] = link
            //                     obj['source'] = result
            //                     obj['pubDate'] = pubDate
            //                     console.log(JSON.stringify(obj))
            //                     technologyRef.push(obj)
            //                     console.log("data pushed to firebase")

            //                 });

            //             }
            //         } else if (guid === oldRssGuid[index2]) {
            //             // console.log(guid)
            //             // console.log(oldRssGuid[index2])
            //             //  console.log('true')
            //             count++
            //             break
            //         }

            //     }if(index==19){
            //         console.log(`the total same news is ${count}`)
            //         // firebase.database().goOffline();

            //     }
            // }

            // new approach
            processData(index, data)

        }

    })
}


// function processData(index, data) {
//     let guid = JSON.stringify(JSON.stringify(data['rss']['channel'][0]['item'][index]['guid'][0]["_"].split('=')[1]))
//     guid = guid.substring(1, guid.length - 1)
//     guid = guid.replace(/\\/g, '');
//     for (let index2 = 0; index2 < 20; index2++) {
//         if (!(guid === oldRssGuid[index2])) {
//             //    console.log(guid)
//             //    console.log(oldRssGuid[index2])
//             //     console.log('false')
//             if(index2==19){
//                 let title = JSON.stringify(data['rss']['channel'][0]['item'][index]['title'][0])
//                 console.log(title)
//                 title = title.substring(1, title.length - 1)
//                 let pubDate = JSON.stringify(data['rss']['channel'][0]['item'][index]['pubDate'][0])
//                 pubDate = pubDate.substring(1, pubDate.length - 1)
//                 let link = JSON.stringify(data['rss']['channel'][0]['item'][index]['link'][0])
//                 link = link.substring(1, title.length - 1)
//                 let desc = JSON.stringify(data['rss']['channel'][0]['item'][index]['description'][0])
//                 var promise = htmlToJson.parse(desc, {
//                     'text': function (doc) {
//                         return doc.find('strong').text();
//                     }
//                 }, function (err, result) {
//                     result = result['text'].split(/\s\s/)[1]
//                     let obj = {}
//                     obj['title'] = title
//                     obj["link"] = link
//                     obj['source'] = result
//                     obj['pubDate'] = pubDate
//                     console.log(JSON.stringify(obj))
//                     technologyRef.push(obj, (error) => {
//                         if(error){
//                             console.log(error)
//                         }else{
//                             index++
//                             if(index<20){
//                                 processData(index, data)
//                             }else{
//                                 firebase.database().goOffline()
//                             }
//                         }
//                     })
//                     console.log("data pushed to firebase")

//                 });
//             }
//         } else if (guid === oldRssGuid[index2]) {
//             index++
//             count++
//             if (index < 20) {
//                 processData(index, data)
//             }else{
//                 firebase.database().goOffline()
//             }
//         }
//     }

// }


// new approach part 2
function processData(index, data) {
    index2 = 0
    let guid = JSON.stringify(JSON.stringify(data['rss']['channel'][0]['item'][index]['guid'][0]["_"].split('=')[1]))
    guid = guid.substring(1, guid.length - 1)
    guid = guid.replace(/\\/g, '');
    secondProcessData(index, index2, guid, data)
    if(index==19){
        console.log("Executed at the last")
        console.log(`total same news are ${count}`)
        // ref.child().remove((error) => {
        //     if(error){
        //         console.log("Error while removing the oldRSS"+error)
        //     }else{
        //         sendNewRSS(0, data)
        //     }
        // })
        // ref.set()
        ref.off('value')
        database.goOffline()
        // sendNewRSS(0, data)
    }
}
function secondProcessData(index, index2, guid, data) {
    if (!(guid === oldRssGuid[index])) {
        if (index2 == 19) {
            // push data to firebase
            let title = JSON.stringify(data['rss']['channel'][0]['item'][index]['title'][0])
            console.log(title)
            title = title.substring(1, title.length - 1)
            let pubDate = JSON.stringify(data['rss']['channel'][0]['item'][index]['pubDate'][0])
            pubDate = pubDate.substring(1, pubDate.length - 1)
            let link = JSON.stringify(data['rss']['channel'][0]['item'][index]['link'][0])
            link = link.substring(1, title.length - 1)
            let desc = JSON.stringify(data['rss']['channel'][0]['item'][index]['description'][0])
            var promise = htmlToJson.parse(desc, {
                'text': function (doc) {
                    return doc.find('strong').text();
                }
            }, function (err, result) {
                result = result['text'].split(/\s\s/)[1]
                let obj = {}
                obj['title'] = title
                obj["link"] = link
                obj['source'] = result
                obj['pubDate'] = pubDate
                console.log(JSON.stringify(obj))
                technologyRef.push(obj, (error) => {
                    if (error) {
                        console.log(error)
                    } else {
                        index++
                        if (index < 20) {
                            processData(index, data)
                        } 
                        // else {
                        //     console.log(`total same news are ${count}`)
                            
                        //     firebase.database().goOffline()
                        // }
                    }
                })
            });
    } else {
        index2++
        if (index2 < 20) {
            secondProcessData(index, index2, guid, data)
        }
    }
}else {
    index++
    count++
    if (index < 20) {
        processData(index, data)
    } 
    // else {
    //     firebase.database().goOffline()
    // }
}
}
// converting xml respnse to json
function xmlToJson(url, callback) {
    var req = https.get(url, function (res) {
        var xml = '';

        res.on('data', function (chunk) {
            xml += chunk;
        });

        res.on('error', function (e) {
            callback(e, null);
        });

        res.on('timeout', function (e) {
            callback(e, null);
        });

        res.on('end', function () {
            parseString(xml, function (err, result) {
                callback(null, result);

            });


        });
    });
}


function sendNewRSS(index, data) {
    if(index==0){
        ref2 = firebase.database().ref('oldRssTechnology')
        ref2.set(JSON.stringify(data['rss']['channel'][0]['item'][index]['guid'][0]["_"].split('=')[1]), (error) => {
            if(error){
                console.log(error)
            }else{
                flag = true
                index++
                console.log(`the value of flag is ${flag}`)
                sendNewRSS(index, data)
            }})

    }else{
    ref2.push(JSON.stringify(data['rss']['channel'][0]['item'][index]['guid'][0]["_"].split('=')[1]), (error) => {
                if(error){
                    console.log(error)
                }else{
                    flag = true
                    index++
                    console.log(`the value of flag is ${flag}`)
                    if(index<20){
                        sendNewRSS(index, data)
                    }else{
                        firebase.database().goOffline()
                    }
                }
            })
        }
    console.log('hello I am inside the new RSS to be send')
}