import MyModule from './MyModule';

import './styles/main.styl';

const h1: HTMLElement | null         = document.getElementById('headline');
const stack_list: HTMLElement | null = document.getElementById('stack-list');

const stack = [
  'Webpack 4'
  ,'TypeScript'
  ,'Stylus'
];

if(h1) new MyModule(h1);

if(stack_list)
{
  stack.forEach((_tech) =>
  {
    const _li: HTMLElement | null = document.createElement('li');

    if(_li)
    {
      _li.textContent = _tech;

      stack_list.appendChild(_li);
    }
  });
}

