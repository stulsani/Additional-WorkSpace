import { Component, OnInit, Input} from '@angular/core';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {
  homeTitle = 'Hello Sumeet';
  myString = 'Sumeet Loves Chicken';
  myBoolean = true;


  game = {
    fname: 'Sumeet',
    lname: 'Tulsani'
  };

  @Input() food;

  constructor() { }

  ngOnInit() {
  }

}
