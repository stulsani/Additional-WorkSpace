import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
})
export class AppComponent {
  title = 'app works!';
  name = 'food';
  food = {
    name: 'Paneer',
    category: 'Vegeterian'
  };

  bell(e){
    alert('I am Belling!!');
  }
}
