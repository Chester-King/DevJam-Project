package com.example.devjams19;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class ObjectActivity extends AppCompatActivity {

    ImageView chair,tv,ref;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_object);

        chair=findViewById(R.id.chair);
        tv=findViewById(R.id.tv);
        ref=findViewById(R.id.ref);

        navigate(chair,"chair");

        navigate(tv,"tv");

        navigate(ref,"ref");

    }

    private void navigate(ImageView view,String object){
        view.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent=new Intent(ObjectActivity.this, ArActivity.class);
                intent.putExtra("object",object);
                startActivity(intent);
            }
        });
    }
}
