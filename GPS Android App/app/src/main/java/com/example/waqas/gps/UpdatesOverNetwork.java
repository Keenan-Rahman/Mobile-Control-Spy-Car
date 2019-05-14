package com.example.waqas.gps;

import android.content.Context;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.Toast;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;

import java.net.URI;
import java.util.ArrayList;

public class UpdatesOverNetwork extends AsyncTask {

    @Override
    protected Object doInBackground(Object[] params) {

        HttpClient httpClient = new DefaultHttpClient();
        HttpPost httpPost = new HttpPost();
        String response = null;
        try {
            //Change the ip according to the internet connection
            URI RequestWeb = new URI("http://172.16.0.252:90/RecieveCoordinates.php");
            httpPost.setURI(RequestWeb);
            ArrayList<NameValuePair> pairs = new ArrayList<>();
            pairs.add(new BasicNameValuePair("latitude",String.valueOf(params[0])));
            pairs.add(new BasicNameValuePair("longitude", String.valueOf(params[1])));
            httpPost.setEntity(new UrlEncodedFormEntity(pairs));
            HttpResponse httpResponse = httpClient.execute(httpPost);
            HttpEntity httpEntity = httpResponse.getEntity();
            response = EntityUtils.toString(httpEntity);
        }catch (Exception ex){
            Log.i("Error", String.valueOf(ex));
        }finally {
            httpPost.abort();
        }
        return response;
    }
}
