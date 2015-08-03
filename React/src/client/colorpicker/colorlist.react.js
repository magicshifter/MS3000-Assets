import React from 'react';

import Component from '../components/component.react';
import * as actions from './actions';
import * as ledActions from '../leds/actions';
import {msg} from '../intl/store';
import color from 'sc-color';

import ColorPickerPreview from './colorpickerpreview.react';

export default class ColorList extends Component {

  removeColor(e) {
    e.preventDefault();
    actions.removeColor(e.target.value);
  }

  changeLed(e) {
    const value = color(e.target.style.backgroundColor).hex6();
    const { id } = this.props;
    ledActions.changeLed({id, value});
  }

  render() {
    const styles = {
      container: {
        width: '10vw',
        height: '100%',
      },
      li: {
        listStyle: 'none',
        display: 'inline-block',
        width: '100%',
      },
    };

    const { colorPicker } = this.props;

    let colorHtmlList = [];
    const colors = colorPicker.get('colors')
      .sort((colorA, colorB) => color(colorA).hue() - color(colorB).hue())
      .map((val, key) => {
        colorHtmlList.push(
          <li key={key} style={styles.li}>
            <ColorPickerPreview
              value={val}
              key={key}
              onClick={(e) => this.changeLed(e)}
              size='3vw'
            />
            <button
              value={val}
              onClick={(e) => this.removeColor(e)}
              title={msg('colorPicker.remove.title')}>
              {msg('colorPicker.remove.text')}
            </button>
          </li>
        );
      });

    return (
      <div style={styles.container}>
        <ul>
          <li>
            <button
              onClick={e => actions.saveColor(this.props.value)}
              title={msg('pages.leds.colorList.saveColorTitle')}
            >
              {msg('pages.leds.colorList.saveColor')}
            </button>
          </li>
          {colorHtmlList}
        </ul>
      </div>
    );
  }
}
