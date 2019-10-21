package com.example.devjams19;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.google.android.material.button.MaterialButton;

public class ParkingActivity extends AppCompatActivity {

    MaterialButton lake;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_parking);


        lake=findViewById(R.id.lake_button);
        lake.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(ParkingActivity.this,LakeActivity.class));
            }
        });

    }
}
