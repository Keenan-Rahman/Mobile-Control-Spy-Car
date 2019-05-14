package com.example.waqas.gps;

import android.app.Service;
import android.content.Intent;
import android.location.Location;
import android.os.Handler;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;

public class GPSservice extends Service {

    Handler handler = new Handler();
    GPSlocation gps;

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    public void onCreate() {
        super.onCreate();
    }

    public int onStartCommand(Intent intent, int flags, int startId) {
        handler.removeCallbacks(sendUpdates);
        handler.postDelayed(sendUpdates, 1000); // 1 second
        return START_STICKY;
    }

    private Runnable sendUpdates = new Runnable() {
        public void run() {
            getGPSupdate();
            handler.postDelayed(this, 60000); // 60 second notifier
        }
    };

    public void getGPSupdate() {
        //create class object
        gps = new GPSlocation(GPSservice.this);
        UpdatesOverNetwork updates = new UpdatesOverNetwork();
        //check if location returned
        if (gps.getLocation() != null) {
            Location location = gps.getLocation();

            Toast.makeText(getApplicationContext(), "Your Location is - \nLat: "
                    + location.getLatitude() + "\nLong: " + location.getLongitude(),
                    Toast.LENGTH_LONG).show();

            String response = String.valueOf(updates.execute(location.getLatitude(), location.getLongitude()));

            Toast.makeText(getApplicationContext(),response,Toast.LENGTH_LONG).show();
            Log.i("--",response);
        }
    }
}
